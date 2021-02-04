# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 15:59:34 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/04 00:17:42 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strdup
	extern	ft_strlen
	extern	ft_strcpy
	extern	malloc
	extern	error

ft_strdup:
	call ft_strlen
	mov rsi, rdi
	mov	rdi, rax
	call malloc wrt ..plt
	cmp	rax, 0
	jl	malloc_error
	mov	rdi, rax
	call ft_strcpy
	ret
malloc_error:
	mov	r9, rax
	call error wrt ..plt
	mov [rax], r9
	mov rax, r9
	ret
