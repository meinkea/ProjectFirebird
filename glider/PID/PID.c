//
//  PID.c
//


#include <PID.h>


#include <stdio.h>
#include <stdlib.h> /* malloc, free, rand */

#include <time.h>


// PUBLIC METHODS
float PM_getKpGain(struct PID *THIS) {
  return THIS->Kp;
}

float PM_getKdGain(struct PID *THIS) {
  return THIS->Kd;
}

float PM_getKiGain(struct PID *THIS) {
  return THIS->Ki;
}

unsigned int PM_getRate(struct PID *THIS) {
  return THIS->rate;
}

float PM_getTarget(struct PID *THIS) {
  return THIS->target;
}

float PM_getState(struct PID * THIS) {
  return THIS->state;
}



int PM_setKpGain(struct PID *THIS, float user_gain) {
  
    xSemaphoreTake(THIS->kpgain_Mutex, portMAX_DELAY);
      THIS->Kp = user_gain;
    xSemaphoreGive(THIS->kpgain_Mutex);
    return;
}

int PM_setKdGain(struct PID *THIS, float user_gain) {
  xSemaphoreTake(THIS->kdgain_Mutex, portMAX_DELAY);
    THIS->Kd = user_gain;
  xSemaphoreGive(THIS->kdgain_Mutex);
  return;
}

int PM_setKiGain(struct PID *THIS, float user_gain) {
  xSemaphoreTake(THIS->kigain_Mutex, portMAX_DELAY);
    THIS->Ki = user_gain;
  xSemaphoreGive(THIS->kigain_Mutex);
  return;
}

int PM_setTarget(struct PID *THIS, float user_target) {
  xSemaphoreTake(THIS->target_Mutex, portMAX_DELAY);
    THIS->target = user_target;
  xSemaphoreGive(THIS->target_Mutex);
  return;
}

int PM_setRate(struct PID *THIS, unsigned int user_rate) {
  xSemaphoreTake(THIS->rate_Mutex, portMAX_DELAY);
    THIS->rate = user_rate;
  xSemaphoreGive(THIS->rate_Mutex);
  return;
}

float PM_computeProp(struct PID *THIS) {
  return (THIS->Kp * (THIS->state - THIS->target));
}

//  Public methods for Thread

// Ignites Thread
int PM_ignition(struct PID *THIS, BaseType_t core) {
    // Overview:
    // 
    //   This function starts a FreeRTOS thread that operates the PID controller loop
    // 
    //
    // Arguments:
    //  
    //   core: Values be 0 or 1.  Used to define which core to pin the controller too.
    // 
    // 
    // Return Values:
    // 
    //    0 ~ Thread was launched, error free and ignition flag was set
    // 
    //   -1 ~ ERROR: Bad core argument. Only 0 or 1 allowed.
    // 
    //   -2 ~ EEROR: Controller has not been allocated.
    // 
    //   -3 ~ ERROR: Thread has already been launched.
    // 
    //   -4 ~ ERROR: xTaskCreatePinnedToCore failed.  Thread failed to launch.
    
  // Aquire operational mutex
  xSemaphoreTake(THIS->opr_Mutex, portMAX_DELAY);
    // Check user argument for core
    if(core != 0 && core != 1) {
      xSemaphoreGive(THIS->opr_Mutex);
      return -1;
    }
    
    // Check if the conroller is allocated
    if(!THIS->alloc_flag) {
      xSemaphoreGive(THIS->opr_Mutex);
      return -2;
    }
    
    // Check if controller's thread is already initialized
    if(THIS->ignition_flag) {
      xSemaphoreGive(THIS->opr_Mutex);
      return -3;
    }
    
    // Launch Thread 
    bool ret = (pdPASS == xTaskCreatePinnedToCore(
      THIS->pelagus,  /* Task function. */
      THIS->name,     /* name of task. */
      20000,          /* Stack size of task */
      THIS,           /* parameter of the task */
      1,              /* priority of the task */
      &(THIS->pelagus_handle),  /* Task handle to keep track of created task */
      core)           /* pin task to core 0, tskNO_AFFINITY for no affinity */
    );
    
    // Check if controller's thread failed to launch
    if(!ret) {
      xSemaphoreGive(THIS->opr_Mutex);
      return -4;
    }
    
    // Set controller's ignition flag to true
    THIS->ignition_flag = true;
  xSemaphoreGive(THIS->opr_Mutex);
  return 0;
}


void PM_pelagus(struct PID *THIS) {
  // Set thread to standby on startup
  vTaskSuspend(THIS);

  // Main for PID controller
  while(1==1) {
    xSemaphoreTake(THIS->opr_Mutex, portMAX_DELAY);
      float temp = 0.0;
      temp = THIS->getKpGain(THIS);
      if(temp > 0.9) {
        temp = 0.8;
        THIS->setKpGain(THIS, temp);//, 0.9);
      }
    xSemaphoreGive(THIS->opr_Mutex);
  }
  
}

int PM_stop(struct PID *THIS) {
  xSemaphoreTake(THIS->opr_Mutex, portMAX_DELAY);
    vTaskSuspend(THIS->pelagus_handle);
  xSemaphoreGive(THIS->opr_Mutex);
  
  return 0;
}

void PM_run(struct PID *THIS) {
  xSemaphoreTake(THIS->opr_Mutex, portMAX_DELAY);
    vTaskResume(THIS->pelagus_handle);
  xSemaphoreGive(THIS->opr_Mutex);
  
  return 0;
}

// Constructor Methods
static struct PID NEW(float Kp, float Kd, float Ki, unsigned int rate, char* name) {
  /*
  // Caclualting Requested memory size
  size_t size = (size_t) amount * sizeof(int);
  // Creating temperary array pointer
  int * ptrArray = NULL;
  // Allocating memory
  ptrArray = (int*) malloc(size);
  // Clearing (Zeroing) newly allocated memory
  memset(ptrArray, 0, size);
  */  
  
  return (struct PID) {
    // INITIALIZING OBJECT VARIABLES  //
    
    // Gains
    .Kp = Kp,
    .Kd = Kd,
    .Ki = Ki,
    
    // Settigns
    .name = name,
    .rate = rate,
	.target = 0.0,

	// Sys State
	.state = 0.0,
	.time_0 = 0.0,
    .time_0 = 0.0,
    
    // Flags
    .alloc_flag = 1,
    .ignition_flag = 0,
    
    // MULTITHREADING SYNCHRONIZATION
    //   Mutexes
    .sys_Mutex = xSemaphoreCreateMutex(),
    .opr_Mutex = xSemaphoreCreateMutex(),
    
    .state_Mutex = xSemaphoreCreateMutex(),
    .target_Mutex = xSemaphoreCreateMutex(),
    .rate_Mutex = xSemaphoreCreateMutex(),
    
    .kpgain_Mutex = xSemaphoreCreateMutex(),
    .kdgain_Mutex = xSemaphoreCreateMutex(),
    .kigain_Mutex = xSemaphoreCreateMutex(),
    
    //   Semaphores
    .gain_Sem = xSemaphoreCreateBinary(),
    
    // Linking Object Methods
    //   get values
    .getKpGain = &PM_getKpGain,
    .getKdGain = &PM_getKdGain,
    .getKiGain = &PM_getKiGain,
    
    .getRate = &PM_getRate,
    
    .getTarget = &PM_getTarget,
    .getState = &PM_getState,
    
    //   set values
    .setKpGain = &PM_setKpGain,
    .setKdGain = &PM_setKdGain,
    .setKiGain = &PM_setKiGain,
    
    .setRate = &PM_setRate,
    .setTarget = &PM_setTarget,
    
    //    MAIN
    .pelagus = &PM_pelagus,
    .ignition = &PM_ignition,
    
    .stop = PM_stop,
    .run = PM_run,
  };

}


const struct tag_PID_Class PID_Class={.NEW=&NEW};
