/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:14:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/05 01:11:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_write_file(const void *buf, size_t count)
{
	int	fd;
	int	expect[2];
	int error_[2];

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
	int error_[2];

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

void	flush_stdin(void)
{
	int	c;

	errno = 0;
	c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
	return ;
}

void	t_read(int fd, void *buf, size_t count, const char *description)
{
	void	*a;
	void	*b;

	errno = 0;
	a = buf;
	b = buf;
	printf("%s:\n", description);
	printf("   read(): from %d, read %zu bytes: ", fd, count);
	fflush(stdout);
	printf(" >>> return: %ld, errno: %d\n", read(fd, a, count), errno);
	fflush(stdout);
	flush_stdin();
	printf("ft_read(): from %d, read %zu bytes: ", fd, count);
	fflush(stdout);
	printf(" >>> return: %ld, errno: %d\n", ft_read(fd, b, count), errno);
	fflush(stdout);
	flush_stdin();
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
