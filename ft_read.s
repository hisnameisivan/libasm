extern __errno_location
section .text
global ft_read
ft_read:
	mov rax, 0
	syscall
	cmp rax, byte 0
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
