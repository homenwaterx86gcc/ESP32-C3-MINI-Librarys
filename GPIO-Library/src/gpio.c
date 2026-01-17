
#include "gpio.h"
int enable_gpio_func(uint8_t pin) {
  if (pin < 22) {
    *gpio_out_sel_table[pin] = STANDART_MODE;
  } else {
    return -1;
  }
  return 0;
};

int set_gpio_mode(uint8_t pin, bool mode) {
  volatile uint32_t *gpio_enable_reg = (volatile uint32_t *)GPIO_ENABLE_REG;
  if (pin < 22) {
    if (mode) {
      *gpio_enable_reg |= (1 << pin);
    } else {
      *gpio_enable_reg &= ~(1 << pin);
    }
  } else {
    return -1;
  }

  return 0;
}

int write_gpio_pin(uint8_t pin, bool value) {
  volatile uint32_t *gpio_out_reg = (volatile uint32_t *)GPIO_OUT_REG;
  if (pin < 22) {
    if (value) {
      *gpio_out_reg |= (1 << pin);
    } else {
      *gpio_out_reg &= ~(1 << pin);
    }
  } else {
    return -1;
  }
  return 0;
}
