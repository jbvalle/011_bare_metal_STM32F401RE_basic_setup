/**
 *@file linkerscript_STM32F401RE.ld
 *@brief Define Memory and OUTPUT Sections 
 *@include linkerscript_STM32F401RE.ld
 **/
ENTRY(Reset_handler)

/** Top of Stack **/
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

/** Define Memory **/
MEMORY
{
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
}

/** Define OUTPUT Sections **/
SECTIONS 
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    }> FLASH

    _sidata = LOADADDR(.data);
    
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;
    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        _ebss = .;
    }> SRAM
}
