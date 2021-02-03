# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 23:46:52 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/02 23:49:32 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	ft_write

ft_write:
	cmp	rsi, 0
	je	except
	mov	rax, 1
	syscall
	cmp	rax, 0
	jl	except
	cmp	rdx, 0
	jge	finish
	jmp	except
finish:
	mov	rax, rdx
	ret
except:
	mov	rax, -1
	ret
