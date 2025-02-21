/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 02:29:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:23:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_write(void)
{
	int	fd;

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
	return ;
}

void	test_write_part2(void)
{
	t_write_file("", 0);
	t_write_file("test", 4);
	t_write_file("1234567890", 10);
	t_write_file("#c#s#p#x#X#e#f#g", 16);
	t_write_file("something\0hidden", 16);
	t_write_file(long_string(), strlen(long_string()));
	t_write(STDOUT_FILENO, NULL, 3);
	t_write(-1, "bom dia", 7);
	t_write(42, "bom dia", 7);
	t_write(9809, "bom dia", 7);
	t_write(98123, "", 1);
	t_write(42, NULL, 7);
	return ;
}

void	test_strcpy(void)
{
	t_strcpy_segfault("");
	t_strcpy_segfault("abc");
	t_strcpy_segfault("123456781235467812345634");
	t_strcpy_segfault("nullchar->\0can't read me");
	t_strcpy_segfault(long_string());
	t_strcpy("");
	t_strcpy("abc");
	t_strcpy("fs;fseluf;s;fs#Ç#li;slefyi;");
	t_strcpy("nullchar->\0can't read me");
	t_strcpy(long_string());
	t_strcpy("\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
	t_strcpy("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
	return ;
}

void	test_strcmp(void)
{
	t_strcmp("ABC", "ABC");
	t_strcmp("ABCD", "ABXD");
	t_strcmp("alhos", "bugalhos");
	t_strcmp("", "");
	t_strcmp("olá", "");
	t_strcmp("bom dia", "");
	t_strcmp("asdklfjasdfj////asdf'''asdf3##", "");
	t_strcmp("the\0hidden", "");
	t_strcmp(long_string(), "");
	t_strcmp("", "");
	t_strcmp("olá", "olá");
	t_strcmp("bom dia", "bom dia");
	t_strcmp("asdklfjasdfj////asdf'''asdf3##", \
"asdklfjasdfj////asdf'''asdf3##");
	t_strcmp("the\0hidden", "the\0hidden");
	t_strcmp(long_string(), long_string());
	test_strcmp_part2();
	return ;
}

void	test_strcmp_part2(void)
{
	printf("Hidden characters inside string ahead:\n");
	t_strcmp("\x01", "\x01");
	t_strcmp("\x02", "\x01");
	t_strcmp("\x01", "\x02");
	t_strcmp("\xff", "\xff");
	t_strcmp("\xfe", "\xff");
	t_strcmp("\xff", "\xfe");
	t_strcmp("\x01\x01", "\x01");
	t_strcmp("\x01\x02", "\x01");
	t_strcmp("\x02\x01", "\x02");
	t_strcmp("\xff\xff", "\xff");
	t_strcmp("\xff\xfe", "\xff");
	t_strcmp("\xfe\xff", "\xfe");
	t_strcmp("\x01", "\x01\x01");
	t_strcmp("\x01", "\x01\x02");
	t_strcmp("\x02", "\x02\x01");
	t_strcmp("\xff", "\xff\xff");
	t_strcmp("\xff", "\xff\xfe");
	t_strcmp("\xfe", "\xfe\xff");
	return ;
}
