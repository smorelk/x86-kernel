// descriptor_tables.c - Initialises the GDT and IDT.

#include "common.h"
#include "descriptor_tables.h"

extern void gdt_flush(u32);

static gdt_entry_t gdt_entries[5];
static gdt_ptr_t gdt_ptr;

static idt_entry_t idt_entries[256];
static idt_ptr_t idt_ptr;

// Interrupt service routines (Defined in assembly code)
//
extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);

void init_descriptor_tables()
{
  init_gdt();
  init_idt();
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

static void init_idt()
{
  idt_ptr.size = (sizeof(idt_entry_t)*256)-1;
  idt_ptr.offset = (u32)&idt_entries;

  idt_set_gate(0, (u32)&isr0, 0x08, 0x8E);
  idt_set_gate(1, (u32)&isr1, 0x08, 0x8E);
  idt_set_gate(2, (u32)&isr2, 0x08, 0x8E);
  idt_set_gate(3, (u32)&isr3, 0x08, 0x8E);
  idt_set_gate(4, (u32)&isr4, 0x08, 0x8E);
  idt_set_gate(5, (u32)&isr5, 0x08, 0x8E);
  idt_set_gate(6, (u32)&isr6, 0x08, 0x8E);
  idt_set_gate(7, (u32)&isr7, 0x08, 0x8E);
  idt_set_gate(8, (u32)&isr8, 0x08, 0x8E);
  idt_set_gate(9, (u32)&isr9, 0x08, 0x8E);
  idt_set_gate(10, (u32)&isr10, 0x08, 0x8E);
  idt_set_gate(11, (u32)&isr11, 0x08, 0x8E);
  idt_set_gate(12, (u32)&isr12, 0x08, 0x8E);
  idt_set_gate(13, (u32)&isr13, 0x08, 0x8E);
  idt_set_gate(14, (u32)&isr14, 0x08, 0x8E);
  idt_set_gate(15, (u32)&isr15, 0x08, 0x8E);
  idt_set_gate(16, (u32)&isr16, 0x08, 0x8E);
  idt_set_gate(17, (u32)&isr17, 0x08, 0x8E);
  idt_set_gate(18, (u32)&isr18, 0x08, 0x8E);
  
  for (int i = 19; i<256; i++)
    idt_set_gate(i, 0, 0, 0);

  idt_flush((u32)&idt_ptr);
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

static void idt_set_gate(s32 n, u32 offset, u16 sel, u8 flags)
{
  idt_entries[n].offset_low = offset & 0xFFFF;
  idt_entries[n].offset_high = (offset >> 16) & 0xFFFF;
  idt_entries[n].sel = sel;
  idt_entries[n].reserved = 0;
  idt_entries[n].flags = flags;
}
