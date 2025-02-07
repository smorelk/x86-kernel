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

extern isr_handler

%macro ISR_NO_ERR 1
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

