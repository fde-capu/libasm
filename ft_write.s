# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:46:52 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/08 08:31:01 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	ft_write
	extern	__errno_location

ft_write:
	mov	rax, 1
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
