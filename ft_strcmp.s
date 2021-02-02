# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 00:07:27 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/02 11:28:47 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strcmp

ft_strcmp:
	mov		r8,					0
char_test:
	cmp		byte [rdi + r8],	0
	je		end_of_str
	cmp 	byte [rsi + r8],	0
	je		end_of_str
	mov		al,					byte [rdi + r8]
	mov		bl,					byte [rsi + r8]
	cmp		al,					bl
	je		increase
	jmp		finish
increase:
	inc		r8
	jmp		char_test
finish:
	sub		rax, rbx
	ret
end_of_str:
	mov		rax,				0
	ret
