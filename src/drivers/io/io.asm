; EduKernel - Huguini79

; I/O driver implementation in assembly

; Define all the functions
global insb
global insw
global outb
global outw

; Implement all the functions
insb:
	; This two lines let us to call this function later in C
	push ebp
	mov ebp, esp

	; Clear the eax register(optional but recommended)
	xor eax, eax
	; Read the I/O address that we passed from C
	mov edx, [ebp + 8]
	; Read the byte from that I/O address
	in al, dx

	; Finally, reset the ebp register
	pop ebp
	ret

insw:
	; This two lines let us to call this function later in C
	push ebp
	mov ebp, esp

	; Clear the eax register(optional but recommended)
	xor eax, eax
	; Read the I/O address that we passed from C
	mov edx, [ebp + 8]
	; Read the byte from that I/O address
	in ax, dx

	; Finally reset the ebp register
	pop ebp
	ret
	
outb:
	; This two lines let us to call this function later in C
	push ebp
	mov ebp, esp

	; Read the I/O address that we passed from C
	mov eax, [ebp + 12]
	mov edx, [ebp + 8]
	; Write the byte to that I/O address
	out dx, al

	; Finally reset the ebp register
	pop ebp
	ret

outw:
	; This two lines let us to call this function later in C
	push ebp
	mov ebp, esp

	; Read the I/O address that we passed from C
	mov eax, [ebp + 12]
	mov edx, [ebp + 8]
	; Write the byte to that I/O address
	out dx, ax

	; Finally reset the ebp register
	pop ebp
	ret
