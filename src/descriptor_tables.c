// descriptor_tables.c - Initialises the GDT and IDT.

#include "common.h"
#include "descriptor_tables.h"

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
}
