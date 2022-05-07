extern _malloc
section .text
global _ft_strdup
_ft_strdup:
	push rdx
	push rcx
	push rdi
	mov rax, 0
	LEN:
	cmp [rdi], byte 0
	je ALLOC
	add rax, 1
	add rdi, 1
	jmp LEN
	ALLOC:
	add rax, 1
	mov rdi, rax
	call _malloc
	mov rdx, rax
	pop rsi
	CPY:
	cmp [rsi], byte 0
	je RETURN
	mov cl, byte [rsi]
	mov [rdx], cl
	add rdx, 1
	add rsi, 1
	jmp CPY
	RETURN:
	mov [rdx], byte 0
	pop rcx
	pop rdx
	ret
