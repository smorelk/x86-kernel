#include "tty.h"
#include "common.h"

void isr_handler(u32 int_no,
                 u32 error_code, 
                 regs_t state)
{
  tty_write("\n\n** INTERRUPT!!! **\n\n");
  tty_write("INT: ");
  tty_write_dec(int_no);
  tty_write(" | ERROR CODE: ");
  tty_write_dec(error_code);
  tty_write("\nEDI: ");
  tty_write_hex(state.edi);
  tty_write(" | ESI: ");
  tty_write_hex(state.esi);
  tty_write(" | EBP: ");
  tty_write_hex(state.ebp);
  tty_write("\nESP: ");
  tty_write_hex(state.esp);
  tty_write(" | EBX: ");
  tty_write_hex(state.ebx);
  tty_write(" | EDX: ");
  tty_write_hex(state.edx);
  tty_write("\nECX: ");
  tty_write_hex(state.ecx);
  tty_write(" | EAX: ");
  tty_write_hex(state.eax);
  tty_write(" | EIP: ");
  tty_write_hex(state.eip);
  tty_write("\n");
}
