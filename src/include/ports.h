
#ifndef PORTS_H
#define PORTS_H
#include <types.h>



 static inline uint16_t inb(uint8_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}


 static inline void outb(uint16_t port,uint8_t val)
{
  
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    
}
 #endif