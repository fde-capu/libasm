# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 15:59:34 by fde-capu          #+#    #+#              #
#    Updated: 2021/02/03 02:14:40 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
	global	ft_strdup
	extern	ft_strlen
	extern	ft_strcpy
	extern	malloc

ft_strdup:
	call ft_strlen
	mov rsi, rdi
	mov	rdi, rax
	call malloc wrt ..plt
	mov	rdi, rax
	call ft_strcpy
	ret
