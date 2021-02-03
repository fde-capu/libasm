/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:05:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/03 02:31:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_strcpy(void)
{
	t_strcpy("Flávio");
	t_strcpy("Carrara");
	t_strcpy("De\0Capua");
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

	buf = calloc(sizeof(char) * 6, 1);
//	t_read(0, buf, 3, "allocated");
	free (buf);
//	t_read(0, buf, 3, "freed (same buf)");
	buf = NULL;
	t_read(0, buf, 3, "buf = NULL");
	return ;
}

void	test_strdup(void)
{
	return ;
}

int	main(void)
{
	hello();
	test_write();
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_read();
	return (0);
}
