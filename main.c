/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:32:11 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/02 13:10:27 by fde-capu         ###   ########.fr       */
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

void	test_strcpy(void)
{
	t_strcpy("Flávio");
	t_strcpy("Carrara");
	t_strcpy("De Capua");
	return ;
}

void	test_strcmp(void)
{
	t_strcmp("ABC", "ABC");
	t_strcmp("ABCD", "ABXD");
	t_strcmp("alhos", "bugalhos");
	return ;
}

void	test_read(void)
{
	void	*buf;
	void	*h;

	buf = calloc(sizeof(char) * 6, 1);
	h = buf;
	t_read(0, h, 1);
	free (buf);
	return ;
}

int		main(void)
{
	hello();
	test_write();
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_read();
	return (0);
}
