# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 21:04:13 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/01 21:57:49 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strlen

ft_strlen:
	mov		r8,	0
char_test:
	cmp BYTE [rdi + r8], 0x0
	jne	increase
	jmp	finish
increase:
	inc	r8
	jmp	char_test
finish:
	mov	rax, r8
	ret
