# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:46:52 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/04 14:13:09 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	ft_write
	extern	__errno_location

ft_write:
	mov	rax, 1
	syscall
	jc	write_failure
	mov	rax, rdx
	ret
write_failure:
	neg	rax
	mov	r9, rax
	call	__errno_location
	mov [rax], r9
	mov	rax, -1
	ret
