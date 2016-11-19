#include <types.h>
#include <interrupts.h>
#include <assembly.h>

#ifndef NUMBER_OF_INTERRUPTS
#define NUMBER_OF_INTERRUPTS (256)
#endif

void DivideByZeroError();
void DebugExceptionError();
void NMI();
void Breakpoint();
void IntoOverflow();
void BoundRangeExceeded();
void InvalidOpcode();
void CoProcessorNotAvailable();
void DoubleFault();
void CoProcessorSegmentOverrun();
void InvalidTaskSegment();
void SegmentNotPresent();
void StackFault();
void GeneralProtectionFault();
void PageFault();
void CoprocessorError();
void AlignmentCheck();
void MachineCheck();
void FloatingPointException();
void SystemCallHandler();

static InterruptTableEntry InterruptTable[NUMBER_OF_INTERRUPTS];

void SetSystemCallHandler(int interruptNumber, void *functionPointer, int dp1);
void SetInterruptHandler(int interruptNumber, void *functionPointer);

void InitializeInterrupts() {
	int i;

	for(i = 0; i < NUMBER_OF_INTERRUPTS; i++) {
		InterruptTable[i].lo = 0;
		InterruptTable[i].css = 0;
		InterruptTable[i].flags = 0;
		InterruptTable[i].hi = 0;
	}

	LoadInterruptDescripterRegister(InterruptTable, sizeof(InterruptTable) - 1);

	SetInterruptHandler(0x00, DivideByZeroError);
	SetInterruptHandler(0x01, DebugExceptionError);
	SetInterruptHandler(0x02, NMI);
	SetInterruptHandler(0x03, Breakpoint);
	SetInterruptHandler(0x04, IntoOverflow);
	SetInterruptHandler(0x05, BoundRangeExceeded);
	SetInterruptHandler(0x06, InvalidOpcode);
	SetInterruptHandler(0x07, CoProcessorNotAvailable);
	SetInterruptHandler(0x08, DoubleFault);
	SetInterruptHandler(0x09, CoProcessorSegmentOverrun);
	SetInterruptHandler(0x0a, InvalidTaskSegment);
	SetInterruptHandler(0x0b, SegmentNotPresent);
	SetInterruptHandler(0x0c, StackFault);
	SetInterruptHandler(0x0d, GeneralProtectionFault);
	SetInterruptHandler(0x0e, PageFault);
	//SetInterruptHandler(0x0f, ....);
	SetInterruptHandler(0x10, CoprocessorError);
	SetInterruptHandler(0x11, AlignmentCheck);
	SetInterruptHandler(0x12, MachineCheck);
	SetInterruptHandler(0x13, FloatingPointException);

	SetSystemCallHandler(0x80, SystemCallHandler, 0x3);
}

void SetSystemCallHandler(int interruptNumber, void *functionPointer, int dp1) {
	InterruptTable[interruptNumber].lo = ((uint32_t)functionPointer) & 0xffff;
	InterruptTable[interruptNumber].hi = ((uint32_t)functionPointer) >> 0x10;
	InterruptTable[interruptNumber].css = 0x18;
	InterruptTable[interruptNumber].flags = 0x8f00 | (dp1 << 13);
}

void SetInterruptHandler(int interruptNumber, void *functionPointer) {
	InterruptTable[interruptNumber].lo = ((uint32_t)functionPointer) & 0xffff;
	InterruptTable[interruptNumber].hi = ((uint32_t)functionPointer) >> 0x10;
	InterruptTable[interruptNumber].css = 0x18;
	InterruptTable[interruptNumber].flags = 0x8e00;
}

void DivideByZeroError() {

}

void DebugExceptionError() {

}

void NMI() {

}

void Breakpoint() {

}

void IntoOverflow() {

}

void BoundRangeExceeded() {

}

void InvalidOpcode() {

}

void CoProcessorNotAvailable() {

}

void DoubleFault() {

}

void CoProcessorSegmentOverrun() {

}

void InvalidTaskSegment() {

}

void SegmentNotPresent() {

}

void StackFault() {

}

void GeneralProtectionFault() {

}

void PageFault() {

}

void CoprocessorError() {

}

void AlignmentCheck() {

}

void MachineCheck() {

}

void FloatingPointException() {

}

void SystemCallHandler() {

}



