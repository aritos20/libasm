section .text

global _ft_strcmp
_ft_strcmp:
    mov rax, -1
    jmp loop

loop:
    inc rax
    mov dl, BYTE [rdi + rax]
    cmp dl, BYTE [rsi + rax]
    jg return2
    jl return1
    je check
    jmp loop

check:
    cmp BYTE [rdi + rax], 0
    je return0
    jmp loop

return2:
    mov rax, 1
    ret

return1:
    mov rax, -1
    ret

return0:
    mov rax, 0
    ret
