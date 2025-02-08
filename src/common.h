// common.h -- Defines typedefs and some global functions.
//             From JamesM's kernel development tutorials.

#ifndef COMMON_H
#define COMMON_H

// Some standard typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32;
typedef          int   s32;
typedef unsigned short u16;
typedef          short s16;
typedef unsigned char  u8;
typedef          char  s8;

struct registers_struct
{
    u32 edi;
    u32 esi;
    u32 ebp;
    u32 esp;
    u32 ebx;
    u32 edx;
    u32 ecx;
    u32 eax;
    u32 eip;
    u32 cs;
    u32 eflags;
    // Defined if CPU is switching from ring 3 (userspace) 
    // to 0 (kernel space)
    u32 user_ss;
    u32 user_esp;
};
typedef struct registers_struct regs_t;


void outb(u16 port, u8 value);
u8 inb(u16 port);
u16 inw(u16 port);

#endif // COMMON_H
