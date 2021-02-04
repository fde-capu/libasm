/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:14:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/04 14:23:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_write(int fd, const void *buf, size_t count)
{
	int	expect[2];
	int error_[2];

	printf("ft_write(%d, '%s', %lu);\t", fd, buf, count);
	errno = 0;
	expect[0] = write(fd, buf, count);
	error_[0] = errno;
	errno = 0;
	expect[1] = ft_write(fd, buf, count);
	error_[1] = errno;
	printf("return\t%d:%d \t| error\t%d:%d\t", \
		expect[0], expect[1], error_[0], error_[1]);
	if ((expect[0] != expect[1]) || (error_[0] != error_[1]))
		err();
	else
		ok();
	nl();
	fflush(stdout);
	return ;
}

void	t_strcpy(char *src)
{
	char	*dest_a;
	char	*dest_b;
	int		len;

	errno = 0;
	len = ft_strlen(src);
	dest_a = calloc(sizeof(char) * (len + 1), 1);
	dest_b = calloc(sizeof(char) * (len + 1), 1);
	printf("%s::errno::%d::strcpy\n", strcpy(dest_a, src), errno);
	fflush(stdout);
	printf("%s::errno::%d::ft_strcpy\n", ft_strcpy(dest_b, src), errno);
	fflush(stdout);
	free(dest_a);
	free(dest_b);
	return ;
}

void	t_strcmp(char *s1, char *s2)
{
	errno = 0;
	printf("%s | %s | %d | err:%d | strcmp\n", s1, s2, strcmp(s1, s2), errno);
	fflush(stdout);
	printf("%s | %s | %d | err:%d | ft_strcmp\n", \
		s1, s2, ft_strcmp(s1, s2), errno);
	fflush(stdout);
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
	(void)s;
	return ;
}
