// EduKernel - Huguini79

// Define the header files

// Define the kernel header file that has our kernel_main function that runs the main execution of the kernel
#include "kernel.h"

// Define the stdio header file that has our vga functions directly(easy for people who works for operating systems like Windows or Linux)
#include "stdio.h"

// Define the keyboard header file that has our initialize_keyboard function, that initializes the keyboard driver

#include "drivers/keyboard/keyboard.h"

// kernel.c, the main execution goes here in kernel_main

void kernel_main() {
	// Initialize the terminal
	terminal_initialize();

	// Print our first message
	printd("================================================================================");
	printd("==============================EduKernel - Huguini79=============================");
	printd("================================================================================\n\n");
	// Print more messages to verify the status of the kernel
	printd("================================================================================");
	printd("= VGA driver has been initialized succesfully                                  =");
	printd("= I/O driver has been initialized succesfully                                  =");
	initialize_keyboard();

	// And the operating system keeps running because of the initialize_keyboard function that allows us to write with the keyboard and write commands

	// End of our kernel :)

}
