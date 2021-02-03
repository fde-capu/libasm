# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:46:52 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/03 14:00:02 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	ft_write
	extern	error

ft_write:
	mov	rax, 1
	syscall
	jc	write_failure
	mov	rax, rdx
	ret
write_failure:
	mov	r9, rax
	call error wrt ..plt
	mov [rax], r9
	mov rax, r9
	ret
