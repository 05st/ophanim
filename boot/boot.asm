[org 0x7c00]
KERNEL_LOC equ 0x1000

BOOT_DISK db 0
mov [BOOT_DISK], dl

mov bp, 0x9000
mov sp, bp

call load_kernel

; Switch to text mode, clear screen
mov ah, 0x0
mov al, 0x3
int 0x10

; Switch to protected mode
call switch_to_pm

%include "boot/print.asm"
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/pm.asm"

[bits 16]
load_kernel:
    mov bx, KERNEL_LOC
    mov dh, 16
    mov dl, [BOOT_DISK]
    call disk_load
    ret

[bits 32]
start:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    jmp KERNEL_LOC

times 510-($-$$) db 0
dw 0xaa55

