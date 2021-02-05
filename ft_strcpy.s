# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 22:12:04 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/04 21:53:43 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strcpy

ft_strcpy:
	mov	r9, 0
loop:
	cmp	byte [rsi + r9], 0
	je	finish
	mov	al, byte [rsi + r9]
	mov byte [rdi + r9], al
	inc	r9
	jmp	loop
finish:
	mov	rax, rdi
	ret
