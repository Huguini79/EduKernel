EduKernel - By Huguini79

EduKernel is a 32 bit kernel created by Huguini79 to teach people how to make their own operating system, like Linux From Scratch(LFS) :)

EduKernel use GRUB as the bootloader, because it's very supported, like in QEMU and in real hardware

Contents:
	src/kernel/kernel.asm - Multiboot kernel in assembly to load the kernel in C with the kernel_main function
	src/kernel/kernel.c - Kernel in C that prints messages and initializes the keyboard driver
	src/kernel/kernel.h - The Kernel header file, this header file has all the functions in kernel.c
	src/drivers/vga/vga.h - The VGA header file, this header file has all the functions for vga.c
	src/drivers/vga/vga.c - VGA in C, this allows to our kernel to print messages
	src/drivers/io/io.h - IO header file, this header file has all the functions for io.asm
	src/drivers/io/io.asm - IO in Assembly, this allows to our kernel to interact with I/O devices, ¡LIKE THE KEYBOARD!
	src/drivers/keyboard/keyboard.c - Keyboard in C, this keyboard driver allows us to interact with our keyboard, reading the status of 0x64(see if the keyboard has been pressed) and the scancodes like 0x01(ESC), and the scancodes allows us to read one specific key and print that to the screen using the VGA driver
	src/drivers/keyboard/keyboard.h - Keyboard header file, this header file has all the functions for keyboard.c
	src/linker/linker.ld - The linker allows us to put all the object files(for example, kernel.o or kernel.asm.o, vga.o, io.asm.o, keyboard.o) in one file called "kernel" in elf i386 format
	build/ - this directory has all the object files
	bin/ - this directory has the final ISO image of our operating system
	iso/ - This directory has the structures for grub
	iso/boot - This directory has the boot image(out kernel in elf i386 format)
	iso/boot/grub - This directory has the grub.cfg configuration that allows us to create the menu for GRUB, to boot the kernel, or for example shutdown or reboot the computer
	build.sh - This is the file that compiles all the kernel files and drivers with nasm and gcc, then it calls the linker, then it makes the ISO image with grub-mkrescue and finally boot our operating system with QEMU, also you can put your ISO image with dd or with rufus or ventoy in a USB and boot it into real hardware(this is so fun) :)
