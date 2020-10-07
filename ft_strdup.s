    extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

section .text

global _ft_strdup
_ft_strdup:
    call _ft_strlen
    push rdi
    mov rdi, rax
    inc rdi
    call _malloc    ;   src pop(rsi) dst rax
    mov rdi, rax
    pop rsi
    call _ft_strcpy
    ret
    