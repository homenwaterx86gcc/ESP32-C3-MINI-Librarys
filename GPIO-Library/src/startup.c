#include <stdint.h>

#define SYSTEM_SYSCLK_CONF_REG (0x0058 + 0x600C0000)
#define PLL_CLK 1
extern int main(void);

void init_clk(void) {
  volatile uint32_t *system_sysclk_conf_reg =
      (volatile uint32_t *)SYSTEM_SYSCLK_CONF_REG;
  // Bit 11 und 10 entscheiden welche Clock verwendet wird. In diesem Fall soll
  // die PLL_CLK verwendet werden
  *system_sysclk_conf_reg |= (PLL_CLK << 10);
  // Jetzt kann noch der Prescaler gesetzt werden. Wir verwendet einen Prescaler
  // von 4 und haben somit 80MHz Bit 0 bis 9 entscheiden über den Prescaler
  *system_sysclk_conf_reg |= 4;
}
