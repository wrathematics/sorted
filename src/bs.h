#ifndef __SORTED_BUBBLESORT_H__
#define __SORTED_BUBBLESORT_H__


/* References:
  * https://en.wikipedia.org/wiki/Bubble_sort
  * https://en.wikipedia.org/wiki/Cocktail_shaker_sort
*/

/* bubble sort */
static inline void sorted_bs(int len, SortData_t *const x)
{
  int i;
  
  while (len > 0)
  {
    int len_new = 0;
    for (i=1; i<len; i++)
    {
      if (x[i-1] > x[i])
      {
        __sorted_swap(x+i-1, x+i);
        len_new = i;
      }
    }
    
    len = len_new;
  }
}



/* bi-directional bubble sort */
static inline void sorted_bdbs(int len, SortData_t *const x)
{
  int i;
  int swapped;
  
  do
  {
    swapped = 0;
    for (i=0; i<len-1; i++)
    {
      if (x[i] > x[i+1])
      {
        __sorted_swap(x+i, x+i+1);
        swapped = 1;
      }
    }
    
    if (!swapped)
      break;
    
    swapped = 0;
    
    for (i=len-2; i>=0; i--)
    {
      if (x[i] > x[i+1])
      {
        __sorted_swap(x+i, x+i+1);
        swapped = 1;
      }
    }
  }
  while (swapped);
}


#endif
