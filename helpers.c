/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 02:32:41 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:23:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	err(void)
{
	g_error_count++;
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
	g_success_count++;
	printf("\x1b[34m[OK]\x1b[0m");
	return ;
}

void	flush_stdin(void)
{
	int	c;

	errno = 0;
	c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
	return ;
}

char	*long_string(void)
{
	return ("Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
	Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. \
	Aliquam bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel \
	fermentum sem. Cras	volutpat, eros eget rhoncus rhoncus, diam augue \
	egestas dolor, vitae rutrum nisi felis sed purus. Mauris magna ex, \
	mollis non suscipit eu, lacinia ac turpis. Phasellus ac tortor et \
	lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere \
	tortor, sit amet consequat amet.");
}
