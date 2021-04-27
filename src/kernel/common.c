#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include "include/serial.h"

size_t strlen(const char * msg) {
  size_t len = 0;
  while(*++msg != '\0') len++;
  return len;
}

void * memcpy(void * dst, const void * src, size_t n) {
  unsigned char * d_temp = dst;
  const unsigned char * s_temp = src;

  while(n-- > 0) *d_temp++ = *s_temp++;

  return dst;
}

void * memset(void *str, int c, size_t n) {
  unsigned char * str_temp = str;
  while(n-- > 0) *str_temp++ = (char)c;
  return str;
}

void __print_int(int num) {
  // Not the most elegant algorithm
  if (num == 0) {
    serial_print_string("0");
    return;
  }

  char number[11];

  int pow_ten = 1000000000;
  int c = 0;
  bool real_num = false;

  if (num < 0) {
    number[c++] = '-';
    num *= -1;
  }

  while(pow_ten > 0) {
    if (num / pow_ten != 0 || real_num) {
      number[c++] = (char) (48 + (num / pow_ten));
      real_num = true;
    }
    num = num % pow_ten;
    pow_ten /= 10;
  }
  number[c++] = '\0';
  serial_print_string(number);
}

void __print_hex(int num) {
  if (num == 0) {
    serial_print_string("0");
    return;
  }

  if(num < 0) {
    serial_print_byte('-');
    num *= -1;
  }

  char hex_num[12];
  int c = 0;
  char temp = 0;

  while(num > 0) {
    if (num <= 9)
      hex_num[c++] = (48 + (num & 0xf));
    else
      hex_num[c++] = (65 + ((num & 0xf) % 10));
    num = num >> 4;
  }

  for(int i = 0; i <= (c-1)/2; i++) {
    temp = hex_num[i];
    hex_num[i] = hex_num[(c-1)-i];
    hex_num[(c-1)-i] = temp;
  }
  hex_num[c++] = '\0';

  serial_print_string("0x");
  serial_print_string(hex_num);
}

void __print_bin(int num) {
  if (num == 0) {
    serial_print_string("0");
    return;
  }

  if(num < 0) {
    serial_print_byte('-');
    num *= -1;
  }

  char bin_num[33];
  int c = 0;
  char temp = 0;
  while(num > 0) {
    bin_num[c++] = (48 + (num & 0x1));
    num = num >> 1;
  }

  for(int i = 0; i <= (c-1)/2; i++) {
    temp = bin_num[i];
    bin_num[i] = bin_num[(c-1)-i];
    bin_num[(c-1)-i] = temp;
  }
  bin_num[c++] = '\0';

  serial_print_string("0b");
  serial_print_string(bin_num);
}

void kernel_printf(const char * msg, ...) {
  va_list args;
  va_start(args, msg);
  while(*msg != '\0') {
    if (msg[0] != '%' && msg[1] != '\0')
      serial_print_byte(*msg);
    else {
      switch(msg[1]) {
        case 'c': {
          // character
          serial_print_byte((unsigned char) va_arg(args, int));
        }
        break;
        case 'd': {
          // number
          __print_int(va_arg(args, int));
        }
        break;
        case 'p':
        case 'x': {
          // hexadecimal
          __print_hex(va_arg(args, int));
        }
        break;
        case 'b': {
          // binary
          __print_bin(va_arg(args, int));
        }
        break;
      }
      msg++;
    }
    msg++;
  }
  va_end(args);
  serial_print_byte('\n');
}
