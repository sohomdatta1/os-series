#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

#define k_printf kernel_printf
/**
 * A implementation of printf that output to the COM1 serial port
 * and allows for debugging printf's without having to worry about scrolling.
 * The following format specifiers work (some are non-standard)
 * %p - Pointer
 * %x - Hexadecimal
 * %b - Binary
 * %d - Number
 * %c - Character
 * %s - String
 *
 * TODO:
 * %o - Octal
 * %f - Float
 */
void kernel_printf(const char * msg, ...);
/**
 * Reverses a string
 */
char * str_rev(char * str, int n);
/**
 * Length of a string
 */
size_t str_len(const char * msg);
void * memcpy(void * dst, const void * src, size_t n);
void * memset(void * str, int c, size_t n);
