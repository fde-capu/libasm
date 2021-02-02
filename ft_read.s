# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:50:37 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/02 15:49:47 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern	___error

section .text
	global		ft_read

ft_read:
	mov	rax,	0
	syscall
	cmp	rdx,	0
	jge	finish
	mov	rdx,	-1
finish:
	mov rax,	rdx
	ret
