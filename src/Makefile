
include env.mk

LINKFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
CFLAGS = -O2
DIRS = boot drivers kernel

all: bin/kernel

bin/kernel : components bin linker.ld
	$(cc) $(LINKFLAGS) -o bin/kernel $(shell find . -type f -name "*.o")

bin:
	mkdir -p bin

components:
	for dir in $(DIRS); do (rm -f $$dir/env.mk; cp env.mk $$dir/; cd $$dir; make $1 || exit 1) || exit 1; done

clean:
	rm -rf bin obj
	rm -f `find . -name "*.o"`
	rm -f `find . -name "*~"`

boot: bin/kernel
	qemu-system-i386 -kernel bin/kernel


