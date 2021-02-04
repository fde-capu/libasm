/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:29:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/04 15:05:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_write(void)
{
	int	fd;

	printf("\n\nft_write() segfault tests:\n");
	t_write(-1, "test", 5);
	close(5);
	fd = -2;
	t_write(fd, NULL, 8);
	t_write(fd, "test", 0);
	t_write(fd, "test", 5);
	t_write(fd, "t", 1);
	t_write(fd, "", 0);
	t_write(fd, "test", 4);
	t_write(fd, "test", 2);
	t_write(fd, NULL, 2);
	t_write(-1, "tt", 2);
	t_write(_POSIX_OPEN_MAX + 1, "tt", 2);
	t_write_file("", 0);
	t_write_file("test", 4);
	t_write_file("1234567890", 10);
	t_write_file("#c#s#p#x#X#e#f#g", 16);
	t_write_file("something\0hidden", 16);
	t_write_file(LONG_STRING, strlen(LONG_STRING));
	t_write(STDOUT_FILENO, NULL, 3);
	t_write(-1, "bom dia", 7);
	t_write(42, "bom dia", 7);
	t_write(9809, "bom dia", 7);
	t_write(98123, "", 1);
	t_write(42, NULL, 7);
	return ;
}

void	test_strlen(void)
{
	t_strlen("Flávio");
	t_strlen("Carrara");
	t_strlen("De Capua");
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
