//
//  fifo.c
//


#ifdef pthread
 #define mutex_lock pthread_mutex_lock
#endif // pthread



#include "fifo.h"
#include <stdio.h>
#include <stdlib.h> /* malloc, free, rand */
#define MAX 1000000


// Public Methods
int PM_getFirstOut(struct intFIFO *THIS) {
  return THIS->hull[THIS->front];
}

int PM_getFirstIn(struct intFIFO *THIS) {
  return THIS->hull[THIS->rear];
}

bool PM_isEmpty(struct intFIFO *THIS) {
  return THIS->itemCount == 0;
}

bool PM_isFull(struct intFIFO *THIS) {
  return THIS->itemCount == THIS->size;
}

int PM_getItemCount(struct intFIFO *THIS) {
   return THIS->itemCount;
}

void PM_enqueue(struct intFIFO *THIS, int data) {
  if( !(THIS->isFull(THIS)) ) {

    if(THIS->rear == THIS->size-1) {
      THIS->rear = -1;
    }
    
    THIS->hull[++(THIS->rear)] = data;
    
    if(THIS->itemCount < THIS->size) { 
      THIS->itemCount++;
    }
  
  }
  return;
}

int PM_dequeue(struct intFIFO *THIS) {
  int data = THIS->hull[THIS->front++];
  if(THIS->front == THIS->size) {
    THIS->front = 0;
  }
  (THIS->itemCount)--;
  return data;
}



// Constructor Methods
static struct intFIFO NEW(unsigned int amount) {
  // Caclualting Requested memory size
  size_t size = (size_t) amount * sizeof(int);
  
  // Creating temperary array pointer
  int * ptrArray = NULL;

  // Allocating memory
  ptrArray = (int*) malloc(size);

  // Clearing (Zeroing) newly allocated memory
  memset(ptrArray, 0, size);
  
  
  return (struct intFIFO) {
	// Initializing Object Variables
    .size = amount,
    .front = 0,
    .rear = -1,
    .itemCount = 0,
    .hull = ptrArray,
    
	// Linking Object Methods
    .getFirstIn = &PM_getFirstIn,
    .getFirstOut = &PM_getFirstOut,
    
    .isEmpty = &PM_isEmpty,
    .isFull = &PM_isFull,
    
    .getItemCount = &PM_getItemCount,
    
    .enqueue = &PM_enqueue,
    .dequeue = &PM_dequeue
  };

}

const struct tag_intFIFO_Class intFIFO_Class={.NEW=&NEW};
