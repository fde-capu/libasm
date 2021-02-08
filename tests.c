/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:14:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:04:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_strcpy_segfault(char *src)
{
	int			expect[2];
	int			error_[2];
	static char	dest_a[(1 << 12)] = {0};

	printf("(segfault) ft_strcpy(dest, \"%s\");\t", src);
	fflush(stdout);
	errno = 0;
	strcpy(dest_a, src);
	error_[0] = errno;
	errno = 0;
	ft_strcpy(dest_a, src);
	error_[1] = errno;
	expect[0] = strcmp(dest_a, src);
	expect[1] = strcmp(dest_a, src);
	ko_ok(expect, error_);
	return ;
}

void	t_strcpy(char *src)
{
	int		expect[2];
	int		error_[2];
	char	*dest_a;
	char	*dest_b;
	int		len;

	len = strlen(src);
	dest_a = calloc(sizeof(char) * (len + 1), 1);
	dest_b = calloc(sizeof(char) * (len + 1), 1);
	printf("ft_strcpy(dest, \"%s\");\t", src);
	fflush(stdout);
	errno = 0;
	strcpy(dest_a, src);
	error_[0] = errno;
	errno = 0;
	ft_strcpy(dest_b, src);
	error_[1] = errno;
	printf("\n\"%s\":\"%s\"\n", dest_a, dest_b);
	expect[0] = strcmp(dest_a, src);
	expect[1] = strcmp(dest_b, src);
	free(dest_a);
	free(dest_b);
	ko_ok(expect, error_);
	return ;
}

void	t_strcmp(char *s1, char *s2)
{
	int		expect[2];
	int		error_[2];

	printf("ft_strcmp(\"%s\", \"%s\");\t", s1, s2);
	fflush(stdout);
	errno = 0;
	expect[0] = strcmp(s1, s2);
	error_[0] = errno;
	errno = 0;
	expect[1] = ft_strcmp(s1, s2);
	error_[1] = errno;
	ko_ok(expect, error_);
	return ;
}

void	t_read(int buf_size, size_t count, char *file)
{
	int		expect[2];
	int		error_[2];
	void	*buf[2];
	int		fd;

	buf[0] = calloc(buf_size, 1);
	buf[1] = calloc(buf_size, 1);
	fd = open(file, O_RDONLY | O_SYNC);
	printf("ft_read(\'%s\', \'calloc(%d, 1)\', %zu);\n", file, buf_size, count);
	fflush(stdout);
	errno = 0;
	expect[0] = read(fd, buf[0], count);
	error_[0] = errno;
	close(fd);
	fd = open(file, O_RDONLY | O_SYNC);
	errno = 0;
	expect[1] = ft_read(fd, buf[1], count);
	error_[1] = errno;
	close(fd);
	ko_ok(expect, error_);
	ko_ok_strcmp(buf[0], buf[1]);
	free(buf[0]);
	free(buf[1]);
	return ;
}

void	t_strdup(char *s)
{
	int		expect[2];
	int		error_[2];
	char	*dup_a;
	char	*dup_b;

	printf("ft_strdup(\"%s\");\t", s);
	fflush(stdout);
	errno = 0;
	dup_a = strdup(s);
	error_[0] = errno;
	errno = 0;
	dup_b = ft_strdup(s);
	error_[1] = errno;
	printf("\n\"%s\":\"%s\"\n", dup_a, dup_b);
	expect[0] = strcmp(dup_a, s);
	expect[1] = strcmp(dup_b, s);
	ko_ok(expect, error_);
	return ;
}
