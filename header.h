/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/02 15:10:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern void		hello(void);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
void			t_write(int fd, const void *buf, size_t count);
void			test_write(void);
extern size_t	ft_strlen(const char *s);
void			t_strlen(const char *s);
void			test_strlen(void);
extern char		*ft_strcpy(char *dest, const char *src);
void			t_strcpy(char *src);
void			test_strcpy(void);
extern int		ft_strcmp(const char *s1, const char *s2);
void			t_strcmp(char *s1, char *s2);
void			test_strcmp(void);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
void			t_read(int fd, void *buf, size_t count);
void			test_read(void);

#endif
