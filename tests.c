/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:14:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/01 23:02:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_write(int fd, const void *buf, size_t count)
{
	printf(" ::    write: %ld, %d\n", write(fd, buf, count), errno);
	fflush(stdout);
	printf(" :: ft_write: %ld, %d\n", ft_write(fd, buf, count), errno);
	fflush(stdout);
	return ;
}

void	t_strlen(const char *s)
{
	printf("%s >%lu< strlen\n", s, strlen(s));
	fflush(stdout);
	printf("%s >%lu< ft_strlen\n", s, ft_strlen(s));
	fflush(stdout);
	return ;
}

void	t_strcpy(char *src)
{
	char	*dest_a;
	char	*dest_b;
	int		len;

	len = ft_strlen(src);
	dest_a = calloc(sizeof(char) * (len + 1), 1);
	dest_b = calloc(sizeof(char) * (len + 1), 1);
	printf("%s::strcpy\n", strcpy(dest_a, src));
	fflush(stdout);
	printf("%s::ft_strcpy\n", ft_strcpy(dest_b, src));
	fflush(stdout);
	free(dest_a);
	free(dest_b);
	return ;
}
