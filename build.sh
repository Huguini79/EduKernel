# EduKernel - Huguini79

# Make sure that you have the toolchain installed, you can install the toolchain like this
# sudo apt install gcc nasm xorriso qemu-system-x86

# Clear the screen
clear
# Compile the kernel.asm and io.asm to object files with nasm
nasm -f elf32 src/kernel/kernel.asm -o build/kernel.asm.o
nasm -f elf32 src/drivers/io/io.asm -o build/io.asm.o
# Compile the c files to object files with gcc
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/kernel/kernel.c -o build/kernel.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/drivers/vga/vga.c -o build/vga.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/drivers/keyboard/keyboard.c -o build/keyboard.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/kernel/string/string.c -o build/string.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/programs/helloworld/helloworld.c -o build/helloworld.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/drivers/shutdown/shutdown.c -o build/shutdown.o
gcc -I./src -m32 -ffreestanding -nostdlib -fno-exceptions -c src/programs/engine/2d/player.c -o build/player.o
# Use the linker to put the object files in a file called "kernel" in elf i386 format to iso/boot directory
ld -m elf_i386 -T src/linker/linker.ld -o iso/boot/kernel build/kernel.asm.o build/io.asm.o build/kernel.o build/vga.o build/keyboard.o build/string.o build/helloworld.o build/shutdown.o build/player.o
# CREATE THE ISO IMAGE OF OUR OPERATING SYSTEM TO THE BIN DIRECTORY :)
grub-mkrescue -o bin/EduKernel.iso iso
# RUN WITH QEMU(NOTE: THIS OPERATING SYSTEM ALSO CAN RUN IN REAL HARDWARE) :)
qemu-system-x86_64 -m 1024 bin/EduKernel.iso
