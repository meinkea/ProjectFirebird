/*! Easy Zero-initializer for when making a new matrix
 *
 */


#include <stddef.h>

#include "../inc/vector.h"


struct vector new_vector = {
  .flags = 0,
  .l = 0,
  .v = NULL,
};


