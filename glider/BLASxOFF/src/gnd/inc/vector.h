/*! Data type for Vatricies used in Linear Algebra
 *
 *
 *
 */


#ifndef VECTOR_H
  #define VECTOR_H


  #ifndef V_ALLOCATED_F
    #define V_ALLOCATED_F 1 //!< Set flag for vector allocation
  #endif // V_ALLOCATED_F
  
  
  //! General Vector datastructure used by BLAS 
  //!
  struct vector {
    int flags;      //!< Flags for vector
    unsigned int l; //!< Number of elements in vector
    char * name;    //!< String identifier for vector
    float * v;     //!< Data pointer for vector
  };
  
  
  //! Used to initilize vector on call
  //! 
  extern struct vector new_vector;






#endif // VECTOR_H
