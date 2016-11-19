#ifndef TERMINAL_H
#define TERMINAL_H

extern void terminal_initialize();
extern void terminal_writestring(const char* data);
extern void terminal_putchar(char c);
extern char* terminal_readstring();

#endif

