# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:50:37 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/08 08:30:52 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	ft_read
	extern	__errno_location

ft_read:
	mov	rax, 0
	syscall
	cmp	rax, 0
	jl	write_failure
	ret
write_failure:
	neg	rax
	mov	r9, rax
	call	__errno_location
	mov [rax], r9
	mov	rax, -1
	ret
