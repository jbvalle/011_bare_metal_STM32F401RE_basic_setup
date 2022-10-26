target extended-remote localhost:3333
monitor reset init
monitor flash write_image erase debug/main.elf
monitor reset
monitor shutdown
disconnect
quit
