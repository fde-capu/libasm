/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/08 08:41:05 by fde-capu         ###   ########.fr       */
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

#define LONG_STRING "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet."

void			err(void);
void			nl(void);
void			ok(void);
void			ko_ok(int expect[2], int error_[2]);
void			ko_ok_strcmp(void *buf_a, void *buf_b);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
void			t_write(int fd, const void *buf, size_t count);
void			t_write_file(const void *buf, size_t count);
void			test_write(void);
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
extern ssize_t	ft_read(int fd, void *buf, size_t count);
void			t_read(int buf_size, size_t count, char *file);
void			test_read(void);
void			t_read_battery(int buf_size, char *fn, int except);
void			t_read_buf_size(int buf_size);
extern char		*ft_strdup(const char *s);
void			t_strdup(char *s);
void			test_strdup(void);

int				g_error_count;
int				g_success_count;

#endif
