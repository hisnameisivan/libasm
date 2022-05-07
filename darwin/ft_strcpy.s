section .text
global _ft_strcpy
_ft_strcpy:
	push rdx
	mov rax, rdi
	WHILE:
	cmp [rsi], byte 0
	je RETURN
	mov dl, byte [rsi]
	mov [rdi], dl
	add rdi, byte 1
	add rsi, byte 1
	jmp WHILE
	RETURN:
	mov [rdi], byte 0
	pop rdx
	ret
