/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 09:20:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

void			err(void);
void			nl(void);
void			ok(void);
void			ko_ok(int expect[2], int error_[2]);
void			ko_ok_strcmp(void *buf_a, void *buf_b);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
void			t_write(int fd, const void *buf, size_t count);
void			t_write_file(const void *buf, size_t count);
void			test_write(void);
void			test_write_part2(void);
extern size_t	ft_strlen(const char *s);
void			t_strlen(const char *s);
void			test_strlen(void);
extern char		*ft_strcpy(char *dest, const char *src);
void			t_strcpy(char *src);
void			t_strcpy_segfault(char *src);
void			test_strcpy(void);
extern int		ft_strcmp(const char *s1, const char *s2);
void			t_strcmp(char *s1, char *s2);
void			test_strcmp(void);
void			test_strcmp_part2(void);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
void			t_read(int buf_size, size_t count, char *file);
void			test_read(void);
void			t_read_battery(int buf_size, char *fn, int except);
void			t_read_battery_no_exception(int buf_size, char *fn);
void			t_read_buf_size(int buf_size);
extern char		*ft_strdup(const char *s);
void			t_strdup(char *s);
void			test_strdup(void);
char			*long_string(void);
int				g_error_count;
int				g_success_count;

#endif
