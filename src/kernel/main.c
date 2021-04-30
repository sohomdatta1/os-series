#include "include/common.h"
#include "include/vga_text.h"

static inline int halt() {
  asm("hlt");
}

static void loop() {
  for(;;);
}

void kernel_main() {
  k_printf("Welcome to tinker-os %s", "Hello");
  text_mode_init();
  text_mode_write("Welcome to tinker-os");
  loop();
  halt();
}
