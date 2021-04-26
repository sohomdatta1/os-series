#include "include/serial.h"

static inline int halt() {
  asm("hlt");
}

void kernel_main() {
  print("Hello World\n");
  halt();
}
