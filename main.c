/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:32:11 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/01 10:28:25 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	t_write(int fd, const void *buf, size_t count)
{
	printf(" ::    write: %ld\n", write(fd, buf, count));
	fflush(stdout);
	printf(" :: ft_write: %ld\n", ft_write(fd, buf, count));
	fflush(stdout);
	return ;
}

void	teste_write(void)
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
}

int	main(void)
{
	hello();
	return (0);
}
