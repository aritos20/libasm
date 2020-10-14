section .text

global		_ft_write
	extern 		___error

_ft_write:
	mov			rax, 0x2000004
	syscall
	jc			_error
	jmp			_exit

_error:
  mov     r15, rax
  call    ___error
  mov     [rax], r15
  mov     rax, -1
  ret

_exit:
	ret

  
