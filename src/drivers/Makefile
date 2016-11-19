include env.mk

shell = /bin/bash
C_FLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I. -I../include
OBJS = $(shell ls -1 *.c | sed 's/\.c/.o/')
SRCS = $(shell ls -1 *.c)

all: $(OBJS) $(SRCS)

.c.o::
	$(cc) $(C_FLAGS) -c $< -o $@

