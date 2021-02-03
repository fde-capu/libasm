/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:29:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/03 02:34:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_write(void)
{
	t_write(0, "WTF", 2);
	t_write(0, "WTF", 3);
	t_write(0, "WTF", 4);
	t_write(1, "WTF", 2);
	t_write(1, "WTF", 3);
	t_write(1, "WTF", 4);
	t_write(2, "WTF", 2);
	t_write(2, "WTF", 3);
	t_write(2, "WTF", 4);
	t_write(1, "WTF", 0);
	t_write(1, "WTF", -1);
	t_write(1, "WTF", -2);
	t_write(1, "WTF", -4);
	return ;
}

void	test_strlen(void)
{
	t_strlen("Flávio");
	t_strlen("Carrara");
	t_strlen("De Capua");
	return ;
}

void	t_write(int fd, const void *buf, size_t count)
{
	errno = 0;
	printf(" ::    write: %ld, %d\n", write(fd, buf, count), errno);
	fflush(stdout);
	printf(" :: ft_write: %ld, %d\n", ft_write(fd, buf, count), errno);
	fflush(stdout);
	return ;
}

void	t_strlen(const char *s)
{
	errno = 0;
	printf("%s >%lu< errno(%d) strlen\n", s, strlen(s), errno);
	fflush(stdout);
	printf("%s >%lu< errno(%d) ft_strlen\n", s, ft_strlen(s), errno);
	fflush(stdout);
	return ;
}
