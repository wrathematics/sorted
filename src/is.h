#ifndef __SORTED_INSERTIONSORT_H__
#define __SORTED_INSERTIONSORT_H__


#include "cdefs.h"


/* References:
  * https://en.wikipedia.org/wiki/Insertion_sort
*/

/* insertion sort */
static inline void sorted_is(const int len, SortData_t *const x)
{
  int i, j;
  SortData_t tmp;
  
  for (i=1; i<len; i++)
  {
    tmp = x[i];
    j = i - 1;
    
    while (j >= 0 && x[j] > tmp)
    {
      x[j+1] = x[j];
      j--;
    }
    
    x[j+1] = tmp;
  }
}


#endif
