#ifndef TTY_H
#define TTY_H

#include "common.h"

static u16 cursor_x;
static u16 cursor_y;
static u16 *vmem = (u16*)0xB8000;

// Write a single character out to the screen.
void tty_put(s8 c);

// Clear screen to all black.
void tty_clear(void);


// Write a null-terminated ascii string out to the screen.
void tty_write(s8 *s);

// Write a 32-bit hex value of n out to the screen
void tty_write_hex(u32 n);

// Write a 32-bit decimal value of n out to the screen.
void tty_write_dec(u32 n);

static void move_cursor();

#endif // TTY_H


