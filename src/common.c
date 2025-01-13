// common.c -- Defines some global functions.
//

#include "common.h"

// Write out a byte to a specific port.
void outb(u16 port, u8 value) {
  asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

// Read a byte from a specific port.
u8 inb(u16 port) {
  u8 ret;
  asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

// Read a word from a specific port.
u16 inw(u16 port) {
  u16 ret;
  asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}
