#ifndef CTRICKS_ERROR_H
#define CTRICKS_ERROR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned int  id;
	char         *name;
	char         *msg;
} error;

#define _printerr(e, s, ...) fprintf(stderr, "\033[1m\033[37m" "%s:%d: " "\033[1m\033[31m" e ":" "\033[1m\033[37m" " ‘%s_error’ " "\033[0m" s "\n", __FILE__, __LINE__, (*__err)->name, ##__VA_ARGS__)
#define printerr(s, ...) _printerr("error", s, ##__VA_ARGS__)
#define printuncaughterr() _printerr("uncaught error", "%s", (*__err)->msg)

#define _errordef(n, _id)                                       \
  error* new_##n##_error_msg(char* msg) {                       \
    error* self = malloc(sizeof(error));                        \
    self->id = _id;                                             \
    self->name = #n;                                            \
    self->msg = msg;                                            \
    return self;                                                \
  }                                                             \
  error* new_##n##_error() { return new_##n##_error_msg(""); }

#define errordef(n) _errordef(n, __COUNTER__ +1)

#define try(try_block, err, err_name, catch_block) {                    \
    error * err_name = NULL;                                            \
    error ** __err = & err_name;                                        \
    void __try_fn() try_block                                           \
      __try_fn();                                                       \
    void __catch_fn() {                                                 \
      if (err_name == NULL) return;                                     \
      unsigned int __##err_name##_id = new_##err##_error()->id;         \
      if (__##err_name##_id != 0 && __##err_name##_id != err_name->id)  \
        printuncaughterr();                                             \
      else if (__##err_name##_id != 0 || __##err_name##_id != err_name->id) \
        catch_block                                                     \
          }                                                             \
    __catch_fn();                                                       \
  }

#define throw(e) { *__err = e; return; }

_errordef(any, 0)

#endif
