#include "tty.h"

void isr_handler(u32 int_no,
                 u32 error_code, 
                 u32 edi, u32 esi, u32 ebp,
                 u32 esp, u32 ebx, u32 edx,
                 u32 ecx, u32 eax, u32 eip, 
                 u32 cs, u32 eflags)
{
  tty_write("\n\n** INTERRUPT!!! **\n\n");
  tty_write("INT: ");
  tty_write_dec(int_no);
  tty_write(" | ERROR CODE: ");
  tty_write_dec(error_code);
  tty_write("\nEDI: ");
  tty_write_hex(edi);
  tty_write(" | ESI: ");
  tty_write_hex(esi);
  tty_write(" | EBP: ");
  tty_write_hex(ebp);
  tty_write("\nESP: ");
  tty_write_hex(esp);
  tty_write(" | EBX: ");
  tty_write_hex(ebx);
  tty_write(" | EDX: ");
  tty_write_hex(edx);
  tty_write("\nECX: ");
  tty_write_hex(ecx);
  tty_write(" | EAX: ");
  tty_write_hex(eax);
  tty_write(" | EIP: ");
  tty_write_hex(eip);
  tty_write("\n");
}
