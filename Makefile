# Makefile for JamesM's kernel tutorials.

CSOURCES=$(shell find -name *.c)
COBJECTS=$(patsubst %.c, %.o, $(CSOURCES))
SSOURCES=$(shell find -name *.s)
SOBJECTS=$(patsubst %.s, %.o, $(SSOURCES))

CC=gcc
CFLAGS=-nostdlib -fno-builtin -m32
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=-felf
LD=ld

all: $(COBJECTS) $(SOBJECTS) link qemu

qemu: 
	qemu-system-i386 -kernel ./kernel

bochs:
	bash scripts/run_bochs.sh

update:
	@echo Updating floppy image
	@bash scripts/update_image.sh

clean:
	@echo Removing object files
	@-rm $(COBJECTS) $(SOBJECTS) kernel

link:
	@echo Linking
	@$(LD) $(LDFLAGS) -o kernel $(SOBJECTS) $(COBJECTS)

.s.o:
	@echo Assembling $<
	@nasm $(ASFLAGS) $<

.c.o:
	@echo Compiling $<
	@$(CC) $(CFLAGS) -o $@ -c $<
