#include "include/common.h"

static inline int halt() {
  asm("hlt");
}

static void loop() {
  for(;;);
}

void kernel_main() {
  k_printf("Hello World %b", -5);
  loop();
  halt();
}
