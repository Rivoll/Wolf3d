/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:53:20 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/10 22:33:58 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>

# include <stdio.h>

# include <fcntl.h>

# include "libft.h"

# define BUFF_SIZE 2

typedef struct		s_str
{
	int				j;
	int				fd;
	int				i;
	char			**tab;
	struct s_str	*next;
}					t_str;

int					get_next_line(const int fd, char **line);

#endif
