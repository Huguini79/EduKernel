// EduKernel - Huguini79

// VGA header file that contains all the VGA functions to write text properly

#ifndef VGA_H
#define VGA_H

// Include the libraries for uint16_t etc...
#include <stdint.h>
#include <stddef.h>

// Define the HEIGHT and WIDTH of the screen
#define VGA_WIDTH 80
#define VGA_HEIGHT 20

// Define all the functions

uint16_t terminal_make_char(char c, char colour);
void terminal_putchar(int x, int y, char c, char colour);
void terminal_writechar(char c, char colour);
void terminal_initialize();
void printd(const char* str);
void limpiar_pantalla();

#endif
