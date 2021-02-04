# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:44:58 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/04 01:49:04 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	hello

hello:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg_hl
	mov rdx, msglen_hl
	syscall
	ret
section	.rodata
	msg_hl:		db		'libasm by fde-capu', 10
	msglen_hl:	equ		$ - msg_hl
