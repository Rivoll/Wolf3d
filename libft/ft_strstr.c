/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:26:45 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/05 22:26:15 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, ft_strlen(little)) == 0)
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
