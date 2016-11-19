
#include <types.h>
#include <assembly.h>

void EnableInterrupts() {
	__asm__ __volatile__("sti");
}

void DisableInterrupts() {
	__asm__ __volatile__("cli");
}

typedef struct _IDTR {
        unsigned short length;
        void* base;
}  __attribute__((__packed__)) IDTR;

void LoadInterruptDescripterRegister(void* base, uint16_t size) {
    
    IDTR interruptDescripterRegister;

    interruptDescripterRegister.length = size;
    interruptDescripterRegister.base = base;

    IDTR* address = &interruptDescripterRegister;

    __asm__( "lidt (%0)" : : "r"(address));
}

