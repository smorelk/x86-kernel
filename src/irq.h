#ifndef IRQ_H
#define IRQ_H

#include "common.h"

#define IRQ(n) ((n) + 0x20)

typedef void (*irq_t)(regs_t);
void register_irq(u8 n, irq_t handler);

static irq_t _idt[256];

#endif // IRQ_H
