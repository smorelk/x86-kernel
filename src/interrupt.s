section .text
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr33       ; Keyboard interrupt handler (IRQ1)

; ISR 0 - isr0: Divide by Zero Exception
isr0:
    pusha
    push dword 0x0      ; Push interrupt number 0 (Divide by Zero Exception)
    popa
    iret

; ISR 1 - isr1: Debug Exception
isr1:
    pusha
    push dword 0x1      ; Push interrupt number 1 (Debug Exception)
    popa
    iret

; ISR 2 - isr2: Non Maskable Interrupt (NMI)
isr2:
    pusha
    push dword 0x2      ; Push interrupt number 2 (NMI)
    popa
    iret

; ISR 3 - isr3: Breakpoint Exception (INT 3)
isr3:
    pusha
    push dword 0x3      ; Push interrupt number 3 (Breakpoint Exception)
    popa
    iret

; ISR 4 - isr4: Overflow Exception (INTO)
isr4:
    pusha
    push dword 0x4      ; Push interrupt number 4 (Overflow Exception)
    popa
    iret

; ISR 5 - isr5: Out of Bounds Exception (BOUND Range Exceeded)
isr5:
    pusha
    push dword 0x5      ; Push interrupt number 5 (Out of Bounds Exception)
    popa
    iret

; ISR 6 - isr6: Invalid Opcode Exception
isr6:
    pusha
    push dword 0x6      ; Push interrupt number 6 (Invalid Opcode Exception)
    popa
    iret

; ISR 7 - isr7: Device Not Available Exception (No FPU)
isr7:
    pusha
    push dword 0x7      ; Push interrupt number 7 (Device Not Available Exception)
    popa
    iret

; ISR 8 - isr8: Double Fault Exception
isr8:
    pusha
    popa
    iret

; ISR 9 - isr9: Coprocessor Segment Overrun (FPU error)
isr9:
    pusha
    push dword 0x9      ; Push interrupt number 9 (Coprocessor Segment Overrun)
    popa
    iret

; ISR 10 - isr10: Invalid TSS (Invalid Task State Segment)
isr10:
    pusha
    popa
    iret

; ISR 11 - isr11: Segment Not Present Exception
isr11:
    pusha
    popa
    iret

; ISR 12 - isr12: Stack Fault Exception
isr12:
    pusha
    popa
    iret

; ISR 13 - isr13: General Protection Fault
isr13:
    pusha
    popa
    iret

; ISR 14 - isr14: Page Fault Exception
isr14:
    pusha
    ; The error code will be pushed by the CPU (it's automatic for Page Faults)
    popa
    iret

; ISR 15 - isr15: Reserved (Unassigned Interrupt Vector)
isr15:
    pusha
    push dword 0xF      ; Push interrupt number 15 (Reserved)
    popa
    iret

; ISR 16 - isr16: x87 FPU Floating-Point Error
isr16:
    pusha
    push dword 0x10     ; Push interrupt number 16 (FPU Floating-Point Error)
    popa
    iret

; ISR 17 - isr17: Alignment Check Exception
isr17:
    pusha
    push dword 0x11     ; Push interrupt number 17 (Alignment Check Exception)
    popa
    iret

; ISR 18 - isr18: Machine Check Exception
isr18:
    pusha
    push dword 0x12     ; Push interrupt number 18 (Machine Check Exception)
    popa
    iret

; ISR 33 - Keyboard Interrupt (IRQ1)
isr33:
    pusha
    push dword 0x21     ; Push interrupt number 33 (Keyboard Interrupt)
    popa
    iret

