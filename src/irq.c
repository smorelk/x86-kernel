#include "common.h"
#include "irq.h"

void register_irq(u8 n, irq_t handler) 
{
  _idt[n] = handler;
}

void irq_handler(u32 int_no,
                 u32 error_code, 
                 regs_t state)
{
  // Signal EOI to both PICs (if the slave is involved)
  if (int_no >= 40) {
    outb(0xA0, 0x20);
  }
  // In either case, signal the master.
  outb(0x20, 0x20);

  if (_idt[int_no] != 0) {
    irq_t handler = _idt[int_no];
    handler(state);
  } 
}
