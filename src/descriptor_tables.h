#ifndef DESC_TABLES
#define DESC_TABLES

struct gdt_entry_struct
{
    u16 limit_low;
    u16 base_low;
    u8 base_middle;
    u8 access;
    u8 granularity;
    u8 base_high;
} __attribute__((packed));

struct gdt_ptr_struct
{
    u16 limit;
    u32 base;
} __attribute__((packed));

typedef struct gdt_ptr_struct gdt_ptr_t;
typedef struct gdt_entry_struct gdt_entry_t;

// Function from ASM
extern void gdt_flush(u32);

// Internal functions
static void init_gdt();
static void gdt_set_gate(s32,u32,u32,u8,u8);

#endif // DESC_TABLES
