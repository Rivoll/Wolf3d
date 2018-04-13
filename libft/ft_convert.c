/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:03:55 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/19 13:17:09 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char				*ft_convert(char *nb, int base_nb, int new_base, int maj)
{
	char			*dest;
	long long int	tmp;

	tmp = ft_atlli_base(nb, base_nb);
	dest = ft_llitoa_base(tmp, new_base, maj);
	return (dest);
}
