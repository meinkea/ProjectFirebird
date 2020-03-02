/*! Easy Zero-initializer for when making a new matrix
 *
 */


#include <stddef.h>

#include "../inc/matrix.h"


struct matrix new_matrix = {
  .flags = 0,
  .r = 0,
  .c = 0,
  .l = 0,
  .name = NULL,
  .m = NULL,
};


