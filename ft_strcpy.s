section .text

global _ft_strcpy
_ft_strcpy:
    mov rax, 0
    jmp loop

loop:
    cmp BYTE [rsi + rax], 0
    je return
    mov dl, BYTE [rsi + rax]
    mov BYTE [rdi + rax], dl
    inc rax
    jmp loop

return:
    mov dl, BYTE [rsi + rax]
    mov BYTE [rdi + rax], dl
    mov rax, rdi
    ret
