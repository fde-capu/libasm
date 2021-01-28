global	hello_world

section	.text

fde_capu:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg_hl
	mov rdx, msglen_hl
	syscall

	mov	rax, 60
	mov	rdi, 0
	syscall

_start:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg_hi
	mov rdx, msglen_hi
	syscall

	mov	rax, 60
	mov	rdi, 0
	syscall

section	.rodata
	msg_hl:	db		'Hello World!', 10
	msglen_hl: equ $ - msg_hl
	msg_hi:	db		'libasm by fde-capu', 10
	msglen_hi: equ $ - msg_hi
