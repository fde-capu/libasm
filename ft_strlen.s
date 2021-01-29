section	.text
	global	hello_world

hello_world:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg_hl
	mov rdx, msglen_hl
	syscall

	mov	rax, 60
	mov	rdi, 0
	syscall

section	.rodata
	msg_hl:	db		'libasm by fde-capu', 10
	msglen_hl: equ $ - msg_hl
