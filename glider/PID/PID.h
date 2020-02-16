//
//  PID.h
//


#ifdef __cplusplus
  extern "C" {
#endif


#ifndef DRIVER_PID_H
#define DRIVER_PID_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



// This is the object that is made
struct PID {
  // INSTANCE VARIABLES //
  
  // Gains
  float Kp;
  float Kd;
  float Ki;
   
  // Settings
  char * name;  // FreeRTOS string name
  unsigned int rate;
  float target;  // Set point
  
  // Sys State
  float state;  // Current state
  float time_0;
  float time_1;
  
  // Flags
  bool alloc_flag;
  bool ignition_flag;
  
  // MULTITHREADING SYNCHRONIZATION
  //   Mutexes
  SemaphoreHandle_t sys_Mutex;  // Cordinates System Thread changes (1 at a time)
  SemaphoreHandle_t opr_Mutex;  // Cordinates Operation
  
  SemaphoreHandle_t target_Mutex;
  SemaphoreHandle_t rate_Mutex;
  SemaphoreHandle_t state_Mutex;
  
  SemaphoreHandle_t kpgain_Mutex;
  SemaphoreHandle_t kdgain_Mutex;
  SemaphoreHandle_t kigain_Mutex;
  
  //   Semaphores
  SemaphoreHandle_t gain_Sem; // To enable/disable changing of gains, without hanging threads
  
  
  // Instance Methods
  float (*getKpGain)(struct PID *THIS);
  float (*getKdGain)(struct PID *THIS);
  float (*getKiGain)(struct PID *THIS);
  
  unsigned int (*getRate)(struct PID *THIS);
  
  float (*getTarget)(struct PID *THIS);
  float (*getState)(struct PID *THIS);
  
  int (*setKpGain)(struct PID *THIS, float user_gain);
  int (*setKdGain)(struct PID *THIS, float user_gain);
  int (*setKiGain)(struct PID *THIS, float user_gain);
  
  int (*setTarget)(struct PID *THIS, float user_target);
  int (*setRate)(struct PID *THIS, unsigned int user_rate);
  
  // THREAD HANDLES
  TaskHandle_t pelagus_handle;
  
  // --- CONTROLLER MAIN ---
  int (*pelagus)(struct PID *THIS);
  int (*ignition)(struct PID *THIS, int core);

  int (*stop)(struct PID *THIS);
  int (*run)(struct PID *THIS);

  // char * (*printMem)(struct PID *THIS, char * Buf);
  
};



// Global Constant Struct containing class variables and methods
// 
// struct tag {
//   ** stuff **
// } intance_name;
//
extern const struct tag_PID_Class {
  // Class Constructor
  struct PID (*NEW)(float Kp, float Kd, float Ki, unsigned int rate, char* name);
  
  
} PID_Class;


#endif // DRIVER_PID_H


#ifdef __cplusplus
  }
#endif


