// Mostly based off OSDev Wiki
#include <stddef.h>
#include <stdbool.h>
#include "include/serial.h"
#include "include/io.h"

#define PORT 0x3F8

static bool serial_port_is_initialized = false;

static bool __init_serial_port() {
  out_byte(PORT + 1, 0x00);
  out_byte(PORT + 3, 0x80);
  out_byte(PORT + 0, 0x03);
  out_byte(PORT + 1, 0x00);
  out_byte(PORT + 3, 0x03);
  out_byte(PORT + 2, 0xC7);
  out_byte(PORT + 4, 0x0B);
  out_byte(PORT + 4, 0x1E);
  out_byte(PORT + 0, 0xAE);

  if(in_byte(PORT + 0) != 0xAE) {
      return false;
  }

  out_byte(PORT + 4, 0x0F);
  return true;
}

void print(const char * msg) {
  if (!serial_port_is_initialized) {
    __init_serial_port();
    serial_port_is_initialized = true;
  }

  while(*msg != '\0' ) {
    // Wait for input byte to be error free
    while(in_byte(PORT + 5) & 0x20 == 0);
    out_byte(PORT, *msg++);
  }
}

