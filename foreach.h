#ifndef CTRICKS_FOREACH_H
#define CTRICKS_FOREACH_H

#include "base.h"

#define foreachnf(type, item, arr, arr_length, func) {  \
    void (*action)(type item) = func;                   \
    for (int i = 0; i<arr_length; i++) action(arr[i]);  \
  }

#define foreachf(type, item, arr, func)             \
	foreachnf(type, item, arr, array_len(arr), func)

#define foreachn(type, item, arr, arr_length, body)                     \
	foreachnf(type, item, arr, arr_length, lambda(void, (type item) body))

#define foreach(type, item, arr, body)            \
	foreachn(type, item, arr, array_len(arr), body)

#define forrange(i, from, to) for (int i = from; i<to; i++)

#endif
