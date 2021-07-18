section .text
global ft_strlen
ft_strlen:
	; push ebp
	; mov ebp, esp
	; add esp, 0xfffffff0
	push ecx
	; push esi
	mov eax, 0
	mov ecx, [esp+0x8]
	WHILE:
	cmp [ecx], byte 0
	je RETURN
	add eax, 1
	add ecx, byte 1
	jmp WHILE
	RETURN:
	; pop esi
	pop ecx
	; pop ebp
	ret
