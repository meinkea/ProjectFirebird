/*! Data type for Matricies used in Linear Algebra
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


#ifndef MATRIX_H
  #define MATRIX_H
  
  
  #ifndef M_ALLOCATED_F
    #define M_ALLOCATED_F 1 //!< Set flag for matrix allocation
  #endif // M_ALLOCATED_F
  
  
  //! General Matrix datastructure used by BLAS 
  //!
  struct matrix {
    int flags;      //!< Flags for matrix
    unsigned int r; //!< Number of Rows in matrix
    unsigned int c; //!< Number of Columns in matrix
    unsigned int l; //!< Number of elements in matrix (l=r*c)
    char * name;    //!< String identifier for matrix
    float ** m;     //!< Data pointer for matrix
  };
  
  
  //! Used to initilize matrix on call
  //! 
  extern struct matrix new_matrix;
  
  
#endif // MATRIX_H


