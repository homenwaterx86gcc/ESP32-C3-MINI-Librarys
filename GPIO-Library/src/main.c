#include "gpio.h"

int main(void) {
  uint8_t pin0 = 0;
  uint8_t pin1 = 1;
  uint8_t pin2 = 2;
  uint8_t pin3 = 3;
  uint8_t pin4 = 4;
  int ret_en0 = enable_gpio_func(pin0);
  int ret_en1 = enable_gpio_func(pin1);
  int ret_en2 = enable_gpio_func(pin2);
  int ret_en3 = enable_gpio_func(pin3);
  int ret_en4 = enable_gpio_func(pin4);

  int ret_set0 = set_gpio_mode(pin0, true);
  int ret_set1 = set_gpio_mode(pin1, true);
  int ret_set2 = set_gpio_mode(pin2, true);
  int ret_set3 = set_gpio_mode(pin3, true);
  int ret_set4 = set_gpio_mode(pin4, true);

  while (1) {
    write_gpio_pin(pin0, true);
    write_gpio_pin(pin1, true);
    write_gpio_pin(pin2, true);
    write_gpio_pin(pin3, true);
    write_gpio_pin(pin4, true);
  }
  return 0;
}
