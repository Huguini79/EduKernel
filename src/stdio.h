#ifndef STDIO_H
#define STDIO_H

#include "drivers/vga/vga.h"

void terminal_initialize();
void printd(const char* str);
void clear();

#endif
