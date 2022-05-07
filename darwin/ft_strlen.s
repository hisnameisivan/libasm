section .text
global _ft_strlen
_ft_strlen:
	mov rax, 0
	WHILE:
	cmp [rdi], byte 0
	je RETURN
	add rax, 1
	add rdi, 1
	jmp WHILE
	RETURN:
	ret
