#!/bin/bash

if [[ $1 = '-d' ]]; then
	qemu-system-i386 -m 256 -kernel bin/kernel -S -gdb tcp::1234 -serial stdio
else
	qemu-system-i386 -m 256 -kernel bin/kernel
fi

