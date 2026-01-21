
#include "gpio.h"

volatile uint32_t *gpio_out_sel_table[] = {
    (volatile uint32_t *)GPIO_FUNC0_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC1_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC2_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC3_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC4_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC5_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC6_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC7_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC8_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC9_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC10_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC11_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC12_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC13_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC14_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC15_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC16_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC17_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC18_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC19_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC20_OUT_SEL_CFG_REG,
    (volatile uint32_t *)GPIO_FUNC21_OUT_SEL_CFG_REG};

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
