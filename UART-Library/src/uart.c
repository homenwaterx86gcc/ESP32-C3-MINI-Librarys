#include "uart.h"

void send_byte(char byte) {
  volatile uint32_t *fifo_send = (volatile uint32_t *)(UART_RXFIFO_RD_BYTE);
  *fifo_send = byte;
}
char receive_byte(void) {
  volatile uint32_t *fifo_read = (volatile uint32_t *)(UART_RXFIFO_RD_BYTE);
  char temp = *fifo_read;
  return temp;
}

void send_n_bytes(char *bytes) {
  while (*bytes != '\n') {
    send_byte(*bytes);
    bytes++;
  }
}
