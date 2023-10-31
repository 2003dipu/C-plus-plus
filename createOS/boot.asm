section .text
global _start

_start:
    ; Set up the stack
    mov esp, stack_space

    ; Load the kernel
    mov ah, 0x02      ; Function code for reading sectors
    mov al, 1         ; Number of sectors to read
    mov ch, 0x00      ; Cylinder 0
    mov dh, 0x00      ; Head 0
    mov dl, 0x80      ; Drive 0 (usually the first hard drive)
    mov bx, kernel    ; Destination memory address
    int 0x13          ; BIOS interrupt for disk I/O

    ; Jump to the kernel
    jmp kernel

section .bss
    stack_space resb 65536   ; 64 KB stack space

section .data
    kernel db "kernel.bin"

times 510 - ($ - $$) db 0  ; Fill the rest of the boot sector with zeros
dw 0xAA55                  ; Boot signature
