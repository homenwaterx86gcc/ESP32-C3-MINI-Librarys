
COMPILER = riscv32-unknown-elf-gcc
OBJCOPY = riscv32-unknown-elf-objcopy
CFLAGS = -Wall -Wextra -g 
LFLAGS = -T linker.ld -nostdlib -nostartfiles

all: firmware.bin

firmware.bin: firmware.elf
	esptool --chip esp32c3 elf2image firmware.elf

firmware.elf:uart.o startup.o main.o
	$(COMPILER) uart.o startup.o main.o $(LFLAGS) -o firmware.elf

uart.o: uart.c
	$(COMPILER) -c $(CFLAGS) uart.c -o uart.o

startup.o: startup.c 
	$(COMPILER) -c $(CFLAGS) startup.c -o startup.o

main.o: main.c
	$(COMPILER) -c $(CFLAGS) main.c -o main.o

clean:
	rm uart.o startup.o main.o firmware.elf firmware.bin


flash:
	esptool --chip esp32c3 --no-stub load_ram firmware.bin
	picocom /dev/ttyUSB0 -b 115200

