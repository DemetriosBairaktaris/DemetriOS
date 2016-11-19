#ifndef ASSEMBLY_H
#define ASSEMBLY_H

void EnableInterrupts();
void DisableInterrupts();

void LoadInterruptDescripterRegister(void* base, uint16_t size);

#endif


