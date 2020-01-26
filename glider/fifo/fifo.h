//
//  fifo.h
//


#ifdef __cplusplus
  extern "C" {
#endif


#ifndef DRIVER_FIFO_H
#define DRIVER_FIFO_H



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



// This is the object that is made
struct intFIFO {
  // Instance Variables
  int size;
  int front;
  int rear;
  int itemCount;
  int * hull;

  // Instance Methods
  int  (*getFirstOut)(struct intFIFO *THIS);
  int  (*getFirstIn)(struct intFIFO *THIS);
  
  bool (*isEmpty)(struct intFIFO *THIS);
  bool (*isFull)(struct intFIFO *THIS);
  
  int  (*getItemCount)(struct intFIFO *THIS);

  void (*enqueue)(struct intFIFO *THIS, int data);
  int  (*dequeue)(struct intFIFO *THIS);
  
};



// Global Constant Struct containing class variables and methods
// 
// struct tag {
//   ** stuff **
// } intance_name;
//
extern const struct tag_intFIFO_Class {
  // Class Constructor
  struct intFIFO (*NEW)(unsigned int amount);


} intFIFO_Class;


#endif // DRIVER_FIFO_H


#ifdef __cplusplus
  }
#endif


