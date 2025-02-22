// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "common.h"
#include "tty.h"
#include "descriptor_tables.h"

extern void set_timer(u32);
extern u32 __end;

int main()
{
  tty_clear();
  tty_write("Hello Kernel Land\n");
  init_descriptor_tables();
  tty_write("GDT initialized\n");
  tty_write("IDT initialized\n");
  set_timer(100);
  tty_write("Timer initialized\n");
}
