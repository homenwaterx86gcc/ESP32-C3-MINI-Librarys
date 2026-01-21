ENTRY(Reset_Handler)

MEMORY {
  iram(rwx) : ORIGIN = 0x40380000, LENGTH = 384K
  dram(rw)  : ORIGIN = 0x3FC80000, LENGTH = 384K
}

SECTIONS {
  . = ORIGIN(iram);
  .text ALIGN(4) : {
    KEEP(*(.vectors))
    KEEP(*(.startup))
    *(.text*)
    *(.rodata*)
  } > iram

  .init_array : {
    KEEP(*(.init_array*))
  } > iram

  .fini_array : {
    KEEP(*(.fini_array*))
  } > iram
  . = ORIGIN(dram);
  .data ALIGN(4) : {
    start_data = .;
    *(.data*)
    end_data = .;
  } > dram

  .bss ALIGN(4) : {
    start_bss = .;
    *(.bss*)
    *(COMMON)
    end_bss = .;
  } > dram
}


