/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:09:03 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:23:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_write_file(const void *buf, size_t count)
{
	int	fd;
	int	expect[2];
	int	error_[2];

	printf("ft_write(fd, \"%s\", %lu);\t", buf, count);
	fflush(stdout);
	fd = remove("_test.txt");
	fd = open("_test.txt", O_CREAT | O_WRONLY, 0666);
	errno = 0;
	expect[0] = write(fd, buf, count);
	error_[0] = errno;
	close(fd);
	fd = remove("_test.txt");
	fd = open("_test.txt", O_CREAT | O_WRONLY, 0666);
	errno = 0;
	expect[1] = ft_write(fd, buf, count);
	error_[1] = errno;
	close(fd);
	ko_ok(expect, error_);
	fd = remove("_test.txt");
	return ;
}

void	t_write(int fd, const void *buf, size_t count)
{
	int	expect[2];
	int	error_[2];

	printf("ft_write(%d, \"%s\", %lu);\t", fd, buf, count);
	fflush(stdout);
	errno = 0;
	expect[0] = write(fd, buf, count);
	error_[0] = errno;
	errno = 0;
	expect[1] = ft_write(fd, buf, count);
	error_[1] = errno;
	ko_ok(expect, error_);
	return ;
}

void	t_strlen(const char *s)
{
	int	expect[2];
	int	error_[2];

	printf("ft_strlen(\"%s\");\t", s);
	fflush(stdout);
	errno = 0;
	expect[0] = strlen(s);
	error_[0] = errno;
	errno = 0;
	expect[1] = strlen(s);
	error_[1] = errno;
	ko_ok(expect, error_);
	return ;
}

void	test_strlen(void)
{
	t_strlen("");
	t_strlen("42 São Paulo");
	t_strlen("fde-capu");
	t_strlen("asdfasdf''///##!!@");
	t_strlen("the\0hidden");
	t_strlen(long_string());
	return ;
}
