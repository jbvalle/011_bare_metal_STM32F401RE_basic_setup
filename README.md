# Bare Metal STM32

[![blog](https://jbvalle.github.io/images/check_out_my_blog.png)](https://jbvalle.github.io/stm32_bare_metal_startup_linker.html)

This project is about setting up a basic bare metal stm32 project. This project does not use any ide or third party libraries. The focus is on getting started with the stm32 platform and understanding the basics of how to set up a project without any abstractions.

![flashing a stm32](./img/stm32_bare_metal_make.gif)

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

_Why did I use Make over CMAKE?_
+ Make is more commonly used for firmware applications that are simple and do not require a lot of customization, while CMake is more commonly used for firmware applications that are more complex and require more customization. As my setup has a very small foot print and the goal was learning core principles of the build process, it made sense using make for my purposes.

_Why did I choose C over C++?_
+ When it comes to firmware applications in embedded systems, there is often a debate about whether to use c++ or c. Both have their pros and cons, so it really comes down to a matter of preference.

+ C++ has the advantage of being a more powerful programming language. It allows for more complex data structures and algorithms, which can be helpful in firmware applications. Additionally, c++ compilers are usually more optimized than c compilers, so code can run faster.

+ On the other hand, c is a simpler language and is often easier to learn and work with. Additionally, c code is often more readable than c++ code, which was helpful as this project was meant for educational purposes.

_Why did I not use SDKs, IDEs and any third party libraries?_
+  This project is not about avoiding tools and abstractions in general. This project is about understanding how things work behind the curtain in order to learn and understand what is usually hidden. By understanding the inner workings of something, we can often get a better grasp of the big picture.


### Installation Requirements
---

> **Warning**
> Please note that it has only been tested on Ubuntu 22.04, and further adjustments may be necessary for other systems. I would be grateful for any messages if you encounter any errors. Thank you!

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

### Want to learn more?
---

[![blog](https://jbvalle.github.io/images/check_out_my_blog.png)](https://jbvalle.github.io/stm32_bare_metal_startup_linker.html)
