# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 22:12:04 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/01 23:39:08 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strcpy

ft_strcpy:
	mov	r8, 0
char_test:
	cmp BYTE [rsi + r8], 0
	jne	copy_byte
	jmp	finish
copy_byte:
	mov	al, BYTE [rsi + r8]
	mov	BYTE [rdi + r8], al
	inc	r8
	jmp	char_test
finish:
	mov	rax, rdi
	ret
