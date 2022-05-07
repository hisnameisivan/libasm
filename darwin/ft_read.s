extern ___error
section .text
global _ft_read
_ft_read:
	mov rax, 0x02000003
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
