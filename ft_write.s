# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:46:52 by fde-capu          #+#    #+#              #
#    Updated: 2021/01/29 17:07:23 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.data
	txt:	db	'XXX'

section .text
	global	ft_write

ft_write:
	mov	rax, 1
	mov	rdi, 1
	mov rsi, txt
	mov rdx, 3
	syscall
	mov	rax, 42
	ret
