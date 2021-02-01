/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/01 10:21:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdio.h>

extern void		hello(void);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern void		t_write(int fd, const void *buf, size_t count);

#endif
