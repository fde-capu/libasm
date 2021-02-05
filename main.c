/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/04 16:25:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	nl();
	test_write();
	nl();
	test_strlen();
	nl();
	test_strcpy();
	nl();
//	test_strcmp();
	nl();
//	test_read();
	nl();
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
