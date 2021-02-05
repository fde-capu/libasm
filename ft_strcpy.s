# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 22:12:04 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/05 01:26:39 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strcpy

ft_strcpy:
	mov	r9, 0
loop:
	mov	al, byte [rsi + r9]
	mov byte [rdi + r9], al
	cmp	al, 0
	je	finish
	inc	r9
	jmp	loop
finish:
	mov	rax, rdi
	ret
