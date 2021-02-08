/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:00:11 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:22:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_read(void)
{
	t_read_buf_size(0);
	t_read_buf_size(1);
	t_read_buf_size(2);
	t_read_buf_size(10);
	t_read_buf_size(15);
	t_read_buf_size(16);
	t_read_buf_size(17);
	t_read_buf_size(63);
	t_read_buf_size(64);
	t_read_buf_size(65);
	t_read_buf_size(1023);
	t_read_buf_size(1024);
	t_read_buf_size(1025);
	t_read_buf_size(999999999);
	return ;
}

void	t_read_buf_size(int buf_size)
{
	int	double_free_fix;

	double_free_fix = 0;
	if (buf_size <= 1023)
		double_free_fix = 1;
	t_read_battery(buf_size, "test_read_0.txt", 0);
	t_read_battery(buf_size, "test_read_1.txt", 0);
	t_read_battery(buf_size, "test_read_3.txt", 0);
	t_read_battery(buf_size, "test_read_15.txt", 0);
	t_read_battery(buf_size, "test_read_16.txt", 0);
	t_read_battery(buf_size, "test_read_17.txt", 0);
	t_read_battery(buf_size, "test_read_alice.txt", double_free_fix);
	t_read_battery(buf_size, "test_read_bin.bin", double_free_fix);
	return ;
}

void	t_read_battery(int buf_size, char *fn, int except)
{
	t_read(buf_size, -999999999999999999, fn);
	t_read(buf_size, -2, fn);
	t_read(buf_size, -1, fn);
	t_read(buf_size, 0, fn);
	t_read(buf_size, 1, fn);
	t_read(buf_size, 4, fn);
	t_read(buf_size, 7, fn);
	t_read(buf_size, 8, fn);
	t_read(buf_size, 9, fn);
	t_read(buf_size, 15, fn);
	t_read(buf_size, 16, fn);
	t_read(buf_size, 17, fn);
	if (except == 0)
		t_read_battery_no_exception(buf_size, fn);
	return ;
}

void	t_read_battery_no_exception(int buf_size, char *fn)
{
	t_read(buf_size, 63, fn);
	t_read(buf_size, 64, fn);
	t_read(buf_size, 65, fn);
	t_read(buf_size, 66, fn);
	t_read(buf_size, 67, fn);
	t_read(buf_size, 100, fn);
	t_read(buf_size, 512, fn);
	t_read(buf_size, 1024, fn);
	t_read(buf_size, 1031, fn);
	t_read(buf_size, 999999999999999999, fn);
	return ;
}

void	test_strdup(void)
{
	t_strdup("");
	t_strdup("olá");
	t_strdup("bom dia");
	t_strdup("asdklfjasdfj////asdf'''asdf3##");
	t_strdup("the\0hidden");
	t_strdup(long_string());
	return ;
}
