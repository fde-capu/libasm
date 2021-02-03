# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 00:07:27 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/02 23:06:48 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strcmp

ft_strcmp:
	mov		r8, 0
	mov		rax, 0
	mov		rbx, 0
char_test:
	mov		al, byte [rdi + r8]
	mov		bl, byte [rsi + r8]
	cmp		al, bl
	je		increase
	jmp		finish
increase:
	inc		r8
	cmp		al, 0
	je		finish
	cmp 	bl, 0
	je		finish
	jmp		char_test
finish:
	sub		rax, rbx
	ret
