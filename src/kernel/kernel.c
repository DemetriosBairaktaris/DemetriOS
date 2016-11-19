#include <terminal.h>
#include <keyboard.h>


#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif


void kernel_main()
{	
	terminal_initialize();
	terminal_writestring("Welcome to DemetriOS\n");
	terminal_writestring("Feel Free to Type some lines....\n");
	keyboard_initialize();	
}

