/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:52:55 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/10 22:29:16 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

static t_str		*ft_addstock(const int fd)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*str;
	t_str			*tmp;

	if (!(tmp = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		str = ft_stradd(str, buf);
	}
	tmp->j = 0;
	tmp->i = 0;
	tmp->fd = fd;
	tmp->tab = ft_strsplit(str, '\n');
	tmp->next = NULL;
	free(str);
	return (tmp);
}

static int			ft_clear(t_str **stock, int fd)
{
	t_str			*tmp;
	t_str			*tmp2;

	tmp = *stock;
	if (tmp->fd == fd)
	{
		*stock = (*stock)->next;
		ft_deltab2((void***)&(tmp->tab), tmp->i);
		free(tmp);
		return (0);
	}
	while (tmp->next->fd != fd)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	ft_deltab2((void***)&(tmp2->tab), tmp2->i);
	free(tmp2);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_str	*stock;
	t_str			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!stock)
	{
		if (!(stock = ft_addstock(fd)))
			return (-1);
	}
	tmp = stock;
	while (tmp->fd != fd && tmp->next)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		if (!(tmp->next = ft_addstock(fd)))
			return (-1);
		tmp = tmp->next;
	}
	if ((*line = tmp->tab[tmp->i]))
	{
		tmp->i++;
		return (1);
	}
	return (ft_clear(&stock, fd));
}
