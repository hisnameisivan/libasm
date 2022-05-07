section .text
global ft_strlen
ft_strlen:
	mov rax, 0
	WHILE:
	cmp [rdi], byte 0
	je RETURN
	add rax, 1
	add rdi, 1
	jmp WHILE
	RETURN:
	ret
