#include "uart.h"

int main(void) {
  while (1) {
    send_n_bytes("Hallo\n");
  }
}
