section .text
global ft_strcmp
ft_strcmp:
	push rdx
	WHILE:
	mov rax, [rdi]
	mov rdx, [rsi]
	cmp al, dl
	jne RETURN
	cmp al, byte 0
	je RETURN
	cmp dl, byte 0
	je RETURN
	add rdi, byte 1
	add rsi, byte 1
	jmp WHILE
	RETURN:
	sub al, dl
	movsx rax, al
	pop rdx
	ret
