/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 07:24:42 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/08 03:37:01 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		*ft_stradd(char *s1, char *s2)
{
	int		i;
	char	*dest;
	int		j;

	if (!s1)
	{
		if (!(s1 = (char*)malloc(sizeof(char))))
			return (NULL);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
