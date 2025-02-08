;   Interrupt.s - Interrupt handling code. Handles CPU-exceptions and also IRQs
section .text
extern isr_handler
extern irq_handler

%macro ISR_NO_ERR 1
global isr%1
isr%1:
    cli             ; Disable interrupts
    pushad           ; Save general-purpose registers
    push dword 0    ; Push dummy error code
    push dword %1   ; Push interrupt number
    call isr_handler ; Call common handler
    add esp, 8      ; Clean up pushed values
    popad            ; Restore general-purpose registers
    sti             ; Re-enable interrupts
    iret            ; Return from interrupt
%endmacro

%macro ISR_ERR 1
global isr%1
isr%1:
    cli             ; Disable interrupts
    pushad           ; Save general-purpose registers
    push dword %1   ; Push interrupt number (error code is already on stack)
    call isr_handler ; Call common handler
    add esp, 4      ; Clean up interrupt number
    popad            ; Restore registers
    sti             ; Re-enable interrupts
    iret            ; Return from interrupt
%endmacro

%macro IRQ 2
    global irq%1
    irq%1:
        cli
        pushad
        push dword 0
        push dword %2
        call irq_handler
        add esp, 8
        popad
        sti
        iret
%endmacro

; IRQs
IRQ 0,  0x20
IRQ 1,  0x21
IRQ 2,  0x22
IRQ 3,  0x23
IRQ 4,  0x24
IRQ 5,  0x25
IRQ 6,  0x26
IRQ 7,  0x27
IRQ 8,  0x28
IRQ 9,  0x29
IRQ 10, 0x2A
IRQ 11, 0x2B
IRQ 12, 0x2C
IRQ 13, 0x2D
IRQ 14, 0x2E
IRQ 15, 0x2F

; CPU Traps

; Exceptions 0-7 (No error codes)
ISR_NO_ERR 0
ISR_NO_ERR 1
ISR_NO_ERR 2
ISR_NO_ERR 3
ISR_NO_ERR 4
ISR_NO_ERR 5
ISR_NO_ERR 6
ISR_NO_ERR 7

; Exceptions 8, 10-14 (Push real error codes)
ISR_ERR 8
ISR_NO_ERR 9
ISR_ERR 10
ISR_ERR 11
ISR_ERR 12
ISR_ERR 13
ISR_ERR 14

; Exceptions 15-18 (No error codes)
ISR_NO_ERR 15
ISR_NO_ERR 16
ISR_NO_ERR 17
ISR_NO_ERR 18

