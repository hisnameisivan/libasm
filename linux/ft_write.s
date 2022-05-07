extern __errno_location
section .text
global ft_write
ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jl ERROR
	ret
	ERROR:
	push rax
	call __errno_location
	pop rdi
	neg rdi
	mov [rax], rdi
	mov rax, -1
	ret
