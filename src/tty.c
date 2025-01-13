
#include "tty.h"

static void move_cursor() {
  u16 cursor_loc = (cursor_y * 80) + cursor_x;
  outb(0x3D4, 14); // Tell VGA we are setting the high byte.
  outb(0x3D5, cursor_loc>>8);
  outb(0x3D4, 15);
  outb(0x3D5, cursor_loc);
}

void tty_put(s8 c) {
  // The background color is black, and the foreground is white.
  u8 bg = 0;
  u8 fg = 0xf;
  u8 color = (bg<<4)|(fg&0xf);
  u16 ch = (color<<8)|c;

  // NOTE: Only handles newlines characters
  if (c == '\n') {
      cursor_x = 0;
      cursor_y++;
      return;
  }
  u16 *location = vmem + (cursor_y * 80 + cursor_x);
  *location = ch;
  cursor_x++;
  
  if (cursor_x >= 80) {
      cursor_x = 0;
      cursor_y++;
  }
  move_cursor();
}

void tty_clear(void) {
  u8 bg = 0;
  u8 fg = 0xf;
  u8 color = (bg<<4)|(fg&0xf);
  u16 blank = (color<<8)|(s8)0x20; // Blank character
  
  for (int i = 0; i < 80*25; i++) {
       vmem[i] = blank;
  }

  cursor_x = 0;
  cursor_y = 0;
  move_cursor();
}

void tty_write(s8 *s) {
  int i = 0;
  while (s[i])
    tty_put(s[i++]);
}


void tty_write_hex(u32 n) {
  int hex_digit = 0;
  int hex_len = 7;
  static s8 hex[8] = {0};
  // NOTE: Print buffer. Max 32-bit value is 8 digits long in hex.
  // Digits are added from right-to-left
  while (n > 0) {
    hex_digit = n%16;
    if (hex_digit < 10) {
      hex[hex_len--] = '0'+hex_digit;
    } else {
      hex[hex_len--] = 'A'+(hex_digit-10);
    }
    n /= 16;
  }
  // NOTE: Digits are printed left-to-right
  for (int i = hex_len+1; i<8;i++) tty_put(hex[i]);
}

void tty_write_dec(u32 n) {
  int dec_digit = 0;
  int dec_len = 9;
  // NOTE: Print buffer. Max 32-bit value is 10 digits long in decimal.
  // Digits are added from right-to-left
  static s8 dec[10]; 
  while (n > 0) {
      dec_digit = n%10;
      dec[dec_len--] = '0'+dec_digit;
      n /= 10;
  }
  // NOTE: Digits are printed from left-to-right
  for (int i = dec_len+1; i<10;i++) tty_put(dec[i]);
}
