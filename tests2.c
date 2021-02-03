/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:29:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/03 12:29:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_write(void)
{
	int	fd;
	int	fd2;

	fd = open("write_out_test-fd.txt", O_CREAT | O_WRONLY);
	fd2 = open("write_out_test-fd2.txt", O_CREAT | O_WRONLY);
	write(fd, "fd test", 8);
	ft_write(fd2, "fd2 = ft_write", 15);
	close(fd);
	close(fd2);
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
