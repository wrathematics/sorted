#ifndef __SORTED_COMMONDEFS_H__
#define __SORTED_COMMONDEFS_H__


/* Change as appropriate */
typedef int SortData_t;

static inline void __sorted_swap(SortData_t *const restrict a, SortData_t *const restrict b)
{
  SortData_t tmp = *a;
  *a = *b;
  *b = tmp;
}


#endif
