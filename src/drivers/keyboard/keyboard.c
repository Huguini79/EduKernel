// EduKernel - Huguini79

// Keyboard implementation

// Define all the necessary header files

// Define the keyboard header file
#include "keyboard.h"

// Define the VGA header file(crucial for print the key that was pressed)
#include "drivers/vga/vga.h"

// Define the I/O header file(crucial for the detection of the keyboard)
#include "drivers/io/io.h"

// Define the bool library
#include <stdbool.h>

// Define the string library
#include "kernel/string/string.h"

// Define the shutdown driver
#include "drivers/shutdown/shutdown.h"

// Define all programs header files
#include "programs/helloworld/helloworld.h"
#include "programs/engine/2d/player.h"

// Define the buffer variable
char buffer[512];

// Define the pos command
int pos = 0;


char tolower(char s1)
{
    if (s1 >= 65 && s1 <= 90)
    {
        s1 += 32;
    }

    return s1;
}

void itoa(int num, char* buffer) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num = num / 10;
    }

    if (isNegative)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

int strnlen_terminator(const char* str, int max, char terminator)
{
    int i = 0;
    for(i = 0; i < max; i++)
    {
        if (str[i] == '\0' || str[i] == terminator)
            break;
    }

    return i;
}

int istrncmp(const char* s1, const char* s2, int n)
{
    unsigned char u1, u2;
    while(n-- > 0)
    {
        u1 = (unsigned char)*s1++;
        u2 = (unsigned char)*s2++;
        if (u1 != u2 && tolower(u1) != tolower(u2))
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}
int strncmp(const char* str1, const char* str2, int n)
{
    unsigned char u1, u2;

    while(n-- > 0)
    {
        u1 = (unsigned char)*str1++;
        u2 = (unsigned char)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}

char* strcpy(char* dest, const char* src)
{
    char* res = dest;
    while(*src != 0)
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }

    *dest = 0x00;

    return res;
}

char* strncpy(char* dest, const char* src, int count)
{
    int i = 0;
    for (i = 0; i < count-1; i++)
    {
        if (src[i] == 0x00)
            break;

        dest[i] = src[i];
    }

    dest[i] = 0x00;
    return dest;
}

bool isdigit(char c)
{
    return c >= 48 && c <= 57;
}
int tonumericdigit(char c)
{
    return c - 48;
}


// Define the add_character
void add_character(char c) {
	buffer[pos++] = c;
	buffer[pos] = '\0';
}

// Define the initialize_keyboard function
void initialize_keyboard() {
	printd("= Keyboard driver has been initialized succesfully                             =================================================================================\nType help to see all the commands\n\nEduKernel$ ");
	// This code has a while(1) loop that always check for a new key pressed
	while(1) {
		// Read the status of the keyboard(this let us to know if the keyboard has been pressed)
		uint8_t status = insb(0x64); // THAT'S WHY WE NEED I/O DRIVER, TO READ THE STATUS OF THE KEYBOARD AND THE SCANCODES :)

		// If the status is 0x01(the keyboard has been pressed)
		if(status & 0x01) {
			// Read the scancode :)
			uint8_t scancode = insb(0x60);

			// With if - else if we are going to verify with the scancode which key has been pressed, more information in https://wiki.osdev.org/PS/2_Keyboard
			if(scancode == 0x01) {
				printd("YOU PRESSED THE ESC KEY :)\n\nEduKernel$ ");
			}
			else if(scancode == 0x1E) {
				printd("a");
				add_character('a');
			}
			else if(scancode == 0x30) {
				printd("b");
				add_character('b');
			}
			else if(scancode == 0x2E) {
				printd("c");
				add_character('c');
			}
			else if(scancode == 0x20) {
				printd("d");
				add_character('d');
			}
			else if(scancode == 0x12) {
				printd("e");
				add_character('e');
			}
			else if(scancode == 0x21) {
				printd("f");
				add_character('f');
			}
			else if(scancode == 0x22) {
				printd("g");
				add_character('g');
			}
			else if(scancode == 0x23) {
				printd("h");
				add_character('h');
			}
			else if(scancode == 0x17) {
				printd("i");
				add_character('i');
			}
			else if(scancode == 0x24) {
				printd("j");
				add_character('j');
			}
			else if(scancode == 0x25) {
				printd("k");
				add_character('k');
			}
			else if(scancode == 0x26) {
				printd("l");
				add_character('l');
			}
			else if(scancode == 0x32) {
				printd("m");
				add_character('m');
			}
			else if(scancode == 0x31) {
				printd("n");
				add_character('n');
			}
			else if(scancode == 0x18) {
				printd("o");
				add_character('o');
			}
			else if(scancode == 0x19) {
				printd("p");
				add_character('p');
			}
			else if(scancode == 0x10) {
				printd("q");
				add_character('q');
			}
			else if(scancode == 0x13) {
				printd("r");
				add_character('r');
			}
			else if(scancode == 0x1F) {
				printd("s");
				add_character('s');
			}
			else if(scancode == 0x14) {
				printd("t");
				add_character('t');
			}
			else if(scancode == 0x16) {
				printd("u");
				add_character('u');
			}
			else if(scancode == 0x2F) {
				printd("v");
				add_character('v');
			}
			else if(scancode == 0x11) {
				printd("w");
				add_character('w');
			}
			else if(scancode == 0x2D) {
				printd("x");
				add_character('x');
			}
			else if(scancode == 0x15) {
				printd("y");
				add_character('y');
			}
			else if(scancode == 0x2C) {
				printd("z");
				add_character('z');
			}
			else if(scancode == 0x39) {
				printd(" ");
			}
			else if(scancode == 0x1C) {
    				size_t len = strlen(buffer);
    				if (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
        				buffer[len - 1] = '\0';
   				 }

    				if (strncmp(buffer, "help", 4) == 0) {
        				clear();
					printd("=========================================================================");
					printd("===========================================Help========================================================================================================================\n\n");
					printd("\nCommands:\n1) clear - Clear the screen\n2) help - shows all the commands - \n3) surprise - There is a surprise :)\n4) credits - Credits of the development of this operating system\n5) hello - Hello World program\n6) exit - Shutdown the system\n7) shutdown - Shutdown the system\n8) playermove - An example of the movement of the player with the 2d game engine");
					printd("\n\nEduKernel$ ");
   				 }
				else if(strncmp(buffer, "surprise", 8) == 0) {
					clear();
					printd("WELCOME TO EDUKERNEL, BY HUGUINI79\n\n");
					for(int i = 0; i < 56; i++) {
						printd("=EduKernel");
					}
					printd("\nEduKernel$ ");
				}
				else if(strncmp(buffer, "credits", 7) == 0) {
					clear();
					printd("Developer: Huguini79\n");
					printd("Development time: 6 hours");
					printd("\n\nEduKernel$ ");
				}
				else if(strncmp(buffer, "clear", 5) == 0) {
					clear();
					printd("EduKernel$ ");
				}
				else if(strncmp(buffer, "hello", 5) == 0) {
					hello();
				}
				else if(strncmp(buffer, "exit", 4) == 0) {
					shutdown();
				}
				else if(strncmp(buffer, "shutdown", 8) == 0) {
					shutdown();
				}
				else if(strncmp(buffer, "playermove", 10) == 0) {
					clear();
					player_move(0, 0);
					player_move(10, 10);
					player_move(5, 5);
					printd("\n\n\n\nEduKernel$ ");
				}
    				else if (buffer[0] == '\0') {
        				printd("\nEduKernel$ ");
    				}
    				else {
        				printd("\nCommand not recognized\n\nEduKernel$ ");
    				}

    				pos = 0;
    				buffer[0] = '\0';

		}
	}

}
}

