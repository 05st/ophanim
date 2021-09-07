gdt_start:
    dd 0
    dd 0
code_desc:
    dw 0xffff
    dw 0
    db 0
    db 10011010b
    db 11001111b
    db 0
data_desc:
    dw 0xffff
    dw 0
    db 0
    db 10010010b
    db 11001111b
    db 0
gdt_end:

gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ code_desc - gdt_start
DATA_SEG equ data_desc - gdt_start

