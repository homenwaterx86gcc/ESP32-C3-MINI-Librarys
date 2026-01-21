#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdlib.h>

#define STARTING_POINT_UART_CONTROLLER_0 0x60000000

#define UART_CLK_CONF_REG (STARTING_POINT_UART_CONTROLLER_0 + 0x0078)

/*To reset the whole UART, please:
• enable the clock for UART RAM by setting SYSTEM_UART_MEM_CLK_EN to 1;
• enable APB_CLK for UARTn by setting SYSTEM_UARTn_CLK_EN to 1
• clear SYSTEM_UARTn_RST to 0;
• write 1 to UART_RST_CORE;
• write 1 to SYSTEM_UARTn_RST;
• clear SYSTEM_UARTn_RST to 0;
• clear UART_RST_CORE to 0.
Note that it is not recommended to reset the APB clock domain module or UART
Core only*/

#define STARTING_POINT_SYSTEM_REGISTERS 0x600C0000

// Um auf SYSTEM_UART_MEMCLK_EN, SYSTEM_UARTn_CLK_EN und SYSTEM_UARTn_RST
// zuzugreifen:
#define SYSTEM_PERIP_CLK_ENO_REG (STARTING_POINT_SYSTEM_REGISTERS + 0x0010)

// Register um auf Rx-Byte aus FIFO zuzugreifen
#define UART_RXFIFO_RD_BYTE (STARTING_POINT_UART_CONTROLLER_0 + 0x0000)

// Register für Baudrate
#define UART_CLKDIV_REG (STARTING_POINT_UART_CONTROLLER_0 + 0x0014)

// Generelles Config-Register für UART
#define UART_CONF0_REG (STARTING_POINT_UART_CONTROLLER_0 + 0x0020)

// void reset_uart(void);
// void set_baudrate(uint32_t baudrate);
void send_byte(char byte);
char receive_byte(void);
void send_n_bytes(char *bytes);
#endif
