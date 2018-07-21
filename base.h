#ifndef CTRICKS_BASE_H
#define CTRICKS_BASE_H

#define lambda(return_type, function_body)        \
	({ return_type __fn__ function_body __fn__; })

#define array_len(arr) (sizeof(arr)/sizeof(arr[0]))

#endif
