// EduKernel - Huguini79

// Shutdown implementation

#include "stdio.h"

#include "shutdown.h"

void shutdown() {
	clear();
	printd("Shutting down the system, please wait...");
	// Older versions of QEMU, in bochs or in real hardware(maybe)
	outw(0xB004, 0x2000);
	// Newer versions of QEMU
	outw(0x604, 0x2000);
	// VirtualBox
	outw(0x4004, 0x3400);
	// Cloud Hypervisor
	outw(0x600, 0x34);
}
