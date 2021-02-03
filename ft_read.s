# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:50:37 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/03 00:47:59 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		ft_read

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
	mov	rax, -1
	ret
