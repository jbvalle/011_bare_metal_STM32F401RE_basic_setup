# Bare Metal STM32

[![blog](https://jbvalle.github.io/images/check_out_my_blog.png)](https://jbvalle.github.io/stm32_bare_metal_startup_linker.html)

This project is about setting up a basic bare metal stm32 project. This project does not use any ide or third party libraries. The focus is on getting started with the stm32 platform and understanding the basics of how to set up a project.

![flashing a stm32](/home/strayker/Downloads/ezgif.com-gif-maker.gif)

Contents
========

 * [Why?](#why)
 * [Installation](#installation)
 * [Usage](#usage)
 * [Output Structure](#output-structure)
 * [Want to learn more?](#want-to-learn-more)

### Why?

Suppose you’ve ever wondered how to set up a bare metal register level C program for developing embedded systems without an IDE or libraries such as HAL or any other abstractions. In that case, this project is for you. In order to understand what is going on, I've provided a link at the top of the page that will take you to a blog post that will help you understand the project a little better. 


There are lot of benefits to learning about this approach, and actually implementing a complete project without any abstractions like IDEs and third-party libraries, a few are:
+ STM32 microcontrollers have a large number of registers, that can be used for various purposes, using this approach really forces one to understand the hardware and all its functionalities from the ground up
+ programming at this low level allows for more flexibility in how the MCU is used
+ register level bare metal programming can be used to optimize the MCU resources
+ using this approach can improve the performance of the MCU
+ this method can also be used to create custom peripherals and interfaces
+ lastly, it is a lot of fun! :)



### Installation Requirements
---

> **Warning**
> Please note that it has only been tested on on Ubuntu 22.04, and further adjustments may be necessary for other systems. I would be grateful for any messages if you encounter any errors. Thank you!

#### Install `ARM GNU Toolchain`: [`Download Link`](https://developer.arm.com/downloads/-/gnu-rm)

some additional recommended installations for the ARM GNU Toolchain:
```bash
$ sudo apt-get install build-essential libgmp3-dev libmpfr-dev libx11-6 libx11-dev texinfo flex bison libmpc-dev libncurses5 libncurses5-dbg libncurses5-dev libncursesw5 libncursesw5-dbg libncursesw5-dev zlibc 
```

#### Install `openocd`

```bash
$ sudo apt-get install -y openocd
```

#### Install `stlink-tools`

```bash
$ sudo apt-get install -y stlink-tools
```

#### Install `gdb-multiarch`

```bash
$ sudo apt-get install -y gdb-multiarch
```

### Usage
---

To start the interactive program, simply run `$ shallow-backup`.


```shell
Usage: make [TARGETS]

Targets:
  -all                        Generate object files and executable
  -flash                      Call OpenOCD, call gdb-multiarch, flash elf file using st-link-v2 debugger
  -debug                      Call OpenOCD, call gdb-multiarch, debug main elf file
  -doxy                       Generate Documentation files using Doxygen
  -clean                      Delete all object and elf files
```

#### Output Structure
---

```shell
./
├── debug/
│   ├── main.elf
│   └── main.map
│
├── docs/
│   ├── html/
│   │   └── ...
│   ├── latex/
│   │   └── ...
│   └── Doxygen
│
├── inc/
│   └── peripherals.h
│
├── src/
│   ├── obj/
│   │   ├── main.o
│   │   └── startup_STM32F401RE.o
│   └── main.c
│
├── startup/
│   ├── debug.gdb
│   ├── flash.gdb
│   ├── linkerscript_STM32F401RE.ld
│   └── startup_STM32F401RE.c
│
└── Makefile
```

### Want to learn?
---

[![blog](https://jbvalle.github.io/images/check_out_my_blog.png)](https://jbvalle.github.io/stm32_bare_metal_startup_linker.html)
