/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 02:32:41 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/04 16:21:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	err(void)
{
	printf("\x1b[35m[KO]\x1b[0m");
	return ;
}

void	nl(void)
{
	printf("\n");
	return ;
}

void	ok(void)
{
	printf("\x1b[34m[OK]\x1b[0m");
	return ;
}
