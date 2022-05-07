extern ___error
section .text
global _ft_write
_ft_write:
	mov rax, 0x02000004
	syscall
	jc ERROR
	ret
	ERROR:
	push rax
	call ___error
	pop rdi
	mov [rax], rdi
	mov rax, -1
	ret
