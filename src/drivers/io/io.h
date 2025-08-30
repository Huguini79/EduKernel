// EduKernel - Huguini79

// I/O header file

#ifndef IO_H
#define IO_h

// Define all the I/O functions
unsigned char insb(unsigned short port);
unsigned short insw(unsigned short port);

void outb(unsigned short port, unsigned char val);
void outw(unsigned short port, unsigned short val);

#endif
