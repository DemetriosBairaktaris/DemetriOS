#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <types.h>

void InitializeInterrupts();
void SetInterruptHandler(int interruptNumber, void *functionPointer);

typedef struct _InterruptTableEntry {
	uint16_t lo;
	uint16_t css;
	uint16_t flags;
	uint16_t hi;
} InterruptTableEntry;

#endif

