/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 08:58:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	g_error_count = 0;
	g_success_count = 0;
	nl();
	test_write();
	nl();
	test_strlen();
	nl();
	test_strcpy();
	nl();
	test_strcmp();
	nl();
	test_strdup();
	nl();
	test_read();
	nl();
	printf("\x1b[34m[OK]:\t%d\x1b[0m\t", g_success_count);
	printf("\x1b[35m[KO]:\t%d\x1b[0m\n", g_error_count);
	return (0);
}

void	ko_ok(int expect[2], int error_[2])
{
	printf("return/result\t%d:%d \t| error\t%d:%d\t", \
		expect[0], expect[1], error_[0], error_[1]);
	if ((expect[0] != expect[1]) || (error_[0] != error_[1]))
		err();
	else
		ok();
	nl();
	fflush(stdout);
	return ;
}
void	ko_ok_strcmp(void *buf_a, void *buf_b)
{
	if (strcmp(buf_a, buf_b))
	{
		printf("string differ: ");
		printf(" \"%s\":\"%s\" ", buf_a, buf_b);
		err();
		nl();
	}
	return ;
}
