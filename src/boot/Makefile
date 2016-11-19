
include env.mk

shell = /bin/bash
AS_FLAGS =
OBJS = $(shell ls -1 *.s | sed 's/\.s/.o/')
SRCS = $(shell ls -1 *.s)

all: $(OBJS) $(SRCS)

.s.o::
	$(AS) $(AS_FLAGS) $< -o $@

