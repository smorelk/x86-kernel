// descriptor_tables.c - Initialises the GDT and IDT.

#include "common.h"
#include "descriptor_tables.h"

extern void gdt_flush(u32);

static gdt_entry_t gdt_entries[5];
static gdt_ptr_t gdt_ptr;

void init_descriptor_tables()
{
  init_gdt();
}

static void init_gdt()
{
  gdt_ptr.limit = (sizeof(gdt_entry_t)*5) -1;
  gdt_ptr.base = (u32)&gdt_entries;

  gdt_set_gate(0,0,0,0,0); // Null segment
  gdt_set_gate(1,0,0xFFFFFFFF, 0x9A, 0xCF); // Kernel code segment
  gdt_set_gate(2,0,0xFFFFFFFF, 0x92, 0xCF); // Kernel data segment
  gdt_set_gate(3,0,0xFFFFFFFF, 0xFA, 0xCF); // User code segment
  gdt_set_gate(4,0,0xFFFFFFFF, 0xF2, 0xCF); // User data segment

  gdt_flush((u32)&gdt_ptr);
}

static void gdt_set_gate(s32 n, u32 base, u32 limit, u8 access, u8 granularity) 
{
  gdt_entries[n].base_low = (base & 0xFFFF);
  gdt_entries[n].base_middle = (base >> 16) & 0xFF;
  gdt_entries[n].base_high = (base >> 24) & 0xFF;
  
  gdt_entries[n].limit_low = (limit & 0xFFFF);
  gdt_entries[n].granularity = (limit>>16)&0x0F;
  gdt_entries[n].granularity |= granularity & 0xF0;
  gdt_entries[n].access = access;
}
