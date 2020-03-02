 /*! Returns a pointer to a printable string of the data in a Vector
  *
  *
  *
  */
 
 
 #ifndef ARRAY_PRINT_H
   #define ARRAY_PRINT_H


  #include <stdio.h>

  #include "esp_attr.h"


  // ----- DEFINE CONSTANTS -----
  // Max and Min value limits for check
  #define BLAS_PRINT_MAX_NUM 9999.0f
  #define BLAS_PRINT_MIN_NUM 0.0001f

  // Define the max digits (should mirror from Max and Min value limits)
  #define BLAS_PRINT_WHL_MAX_DIGITS 4 // max digits to the left of '.'
  #define BLAS_PRINT_DEC_MAX_DIGITS 4 // max digits to the right of '.'

  // Initial Place Value Extractor
  #define BLAS_PRINT_WHL_MODL 1000 // = 10^(WHL_MAX_DIGITS-1)
  #define BLAS_PRINT_DEC_MODL 1000 // = 10^(DEC_MAX_DIGITS-1)

  // TOTAL Size of char buffer
  #define BLAS_PRINT_ARRAY__NUM_DIGITS (BLAS_PRINT_WHL_MAX_DIGITS+1+BLAS_PRINT_DEC_MAX_DIGITS+1)

  // Index of '.' char in buffer
  #define DECIMAL_INDEX (BLAS_PRINT_WHL_MAX_DIGITS+1)

  // Int representation of the '0' char
  #define CHAR_0_ 48


  static inline void IRAM_ATTR array_print(
         char * buf,        //!< Pointer to string buffer for printing
         const float sclSrc  //!< Array pointer for source data
       )
         __attribute__((always_inline))
         __attribute__((nonull))
  ;


  static inline int check_limits(
        float num,
        char * buf
      )
        __attribute__((always_inline))
  ;

  static inline void clear_string(
         char * buf
      )
        __attribute__((always_inline))
  ;

  static inline void place_decimal(
         char * buf
       )
        __attribute__((always_inline))
  ;
  
  static inline char get_num_sign(
         float num
       )
        __attribute__((always_inline))
  ;


  void IRAM_ATTR array_print(char * buf, const float sclSrc) {
    // Check for out of limit number
    if (check_limits(sclSrc, buf) != 0) {
      return;
    }

    unsigned int head = (unsigned int) sclSrc;
    unsigned int tail = (unsigned int) ((sclSrc - (float) head) * BLAS_PRINT_DEC_MODL * 10);

    clear_string(buf);   //  Clear all places in string (set them to spaces)
    place_decimal(buf);  //  Place period/decimal (inline this manually)
    buf[0] = get_num_sign(sclSrc);  // Place sign (+ or -) (inline this manually)


    // ---- Place WHOLE Digits
    //  This method uses integer modulus division
    //  Thought and care was taken to make sure that this methods division uses the least number of divisions required
    //     1. Start by dividing the highest place value, finding that digit.
    //     2. This part is subtracted out of integer that is to be string'tized
    //     This processed is repeated up to the one's place
    //    In all, this means that there are maximum of (9+1)*(n-1) divisions, where n is the number of place values in a number
    //      --> 9 divs for the modulus, 1 to decrement the modulator (modl)

    unsigned int modl = 0;
    unsigned int unit = 0;

    modl = BLAS_PRINT_WHL_MODL;  // used to help extract each place value by modulus division
    unit = head;  // the digit that is extracted at each place value, set it to head

    for (unsigned int I=0; I<BLAS_PRINT_WHL_MAX_DIGITS; ++I) {
      head %= modl;  // Step 1 - Pop off the first (biggest) digget from the head.  9 subtractions Max
      unit -= head;  // Step 2 - Get the digit that was popped off from the head
      unit /= modl;  // Step 3 - Remove preceeding zeros
      buf[I + 1] = CHAR_0_ + unit; // Convert number to Char and add to 0-Char to calc X-Char

      // For next loop
      modl /= 10;    // Decrement the modulus
      unit = head;
    }

    modl = BLAS_PRINT_DEC_MODL;  // used to help extract each place value by modulus division
    unit = tail;  // the digit that is extracted at each place value, set it to head

    for (unsigned int I=0; I<BLAS_PRINT_DEC_MAX_DIGITS; ++I) {
      tail %= modl;  // Step 1 - Pop off the first (biggest) digget from the tail.  9 divisions Max
      unit -= tail;  // Step 2 - Get the digit that was popped off from the tail
      unit /= modl;  // Step 3 - Remove preceeding zeros

      buf[I + DECIMAL_INDEX+1] = CHAR_0_ + unit; // Convert number to Char and add to 0-Char to calc X-Char

      // For next loop
      modl /= 10;    // Decrement the modulus
      unit = tail;
    }

    return;
  }


  // Check for if the float is out of the limits defined by BLAS_PRINT_MAX_NUM and BLAS_PRINT_MIN_NUM
  int check_limits(float num, char * buf) {
    if (num > BLAS_PRINT_MAX_NUM) {
      memcpy(buf, " Infinity ", BLAS_PRINT_ARRAY__NUM_DIGITS-1);
      return -1;
    } else if (num < BLAS_PRINT_MIN_NUM) {
      memcpy(buf, "-   0.0000", BLAS_PRINT_ARRAY__NUM_DIGITS-1);
      return -2;
    } else {
      return 0;
    }
  }


  // Clears all buffer to spaces (' ')
  void clear_string(char * buf) {
    for (unsigned int I = 0; buf[I] != '\0'; ++I) {
      buf[I] = ' ';
    }
    return;
  }


  // Places decimal in buffer indicated by DECIMAL_INDEX
  void place_decimal(char * buf) {
    //   num whole dig + (   num of ' chars  ) + (sign)  ~ This calulation is done to reduce this part to O(1) (constant) runtime
    buf[DECIMAL_INDEX] = '.';
    return;
  }


  // Sets the sign of the number ('-' or '+')
  char get_num_sign(float num) {
    return (num < 0.0) ? '-' : '+';
  }



#endif // ARRAY_PRINT_H


