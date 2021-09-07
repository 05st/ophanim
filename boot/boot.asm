[org 0x7c00]
KERNEL_LOC equ 0x1000

mov [BOOT_DISK], dl

call load_kernel
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
    jmp KERNEL_LOC

BOOT_DISK db 0

times 510 - ($ - $$) db 0
db 0x55, 0xaa
