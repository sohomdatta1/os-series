#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

#define k_printf kernel_printf

void kernel_printf(const char *, ...);
char * str_rev(char *, int);
size_t str_len(const char *);
void * memcpy(void *, const void *, size_t);
void * memset(void *, int, size_t);
