; EduKernel - Huguini79
; In this file, we create a multiboot kernel(for grub) that loads our kernel with the function kernel_main

; Define the bits(32)
BITS 32

section .text

; Define the multiboot
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)

; Define the start function(THIS IS ESSENTIAL FOR THE LINKER)
global start

; Define our kernel_main function to also use this function in kernel.c
extern kernel_main

; Start function starts
start:
	; Disable interrupts
	cli
	; CALL OUR C KERNEL
	call kernel_main
	; Wait for another interrumpt
	hlt

section .bss
stack_space: resb 65536 ; 64 KB of stack
