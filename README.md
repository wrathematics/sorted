# sorted

Some basic sorting functions implementated in C99.  The implementation is header-only for ease of use and performance.



## Installation

Just copy `cvector.h` over to wherever and include it via `#include "cvector.h"`.  The license is extremely permissive (see License section below).

The default storage type is `int`.  Change the definition of `SortData_t` in the header as appropriate for your needs.



## API

The "public" API is:

```c
// bubble sort
void sorted_bs(int len, SortData_t *const x);

// bi-directionalbubble sort
void sorted_bdbs(int len, SortData_t *const x);

// insertion sort
void sorted_is(const int len, SortData_t *const x);

// quick sort
void sorted_qs(int len, SortData_t *const x);
```



## License

This project is licensed under the "0-clause" BSD.  Basically I don't care how or why you use it, but it comes with no warranty of any kind.

A longer explanation is that it is subject to the usual restrictions of the 2-Clause BSD license, except that you do not have to retain copyright notices on source or binary copies.  Note that this should not be construed as a dereliction of copyright or "public domaining".  It's just meant to be extremely permissive.
