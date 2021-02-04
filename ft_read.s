# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:50:37 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/04 00:40:12 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		ft_read
	extern	error

ft_read:
	cmp	rsi, 0
	je	except
	mov	rax, 0
	syscall
	cmp	rax, 0
	jl	except
	cmp	rdx, 0
	jge	finish
	mov	rdx, -1
finish:
	mov	rax, rdx
	ret
except:
	mov	r9, rax
	call error wrt ..plt
	mov [rax], r9
	mov rax, r9
	ret
