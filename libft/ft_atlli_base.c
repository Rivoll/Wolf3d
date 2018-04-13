/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atlli_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:12:23 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/19 13:28:28 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

long long int		ft_atlli_base(char *nb, int base_nb)
{
	long long int	result;
	int				sign;
	int				i;

	if (base_nb > 36 || base_nb < 2)
		return (-1);
	sign = 1;
	i = 0;
	result = 0;
	if (nb[i] == '+')
		i++;
	else if (nb[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			result = result * base_nb + nb[i++] - '0';
		else if (nb[i] >= 'a' && nb[i] <= 'j')
			result = result * base_nb + 30 + nb[i++] - 117;
	}
	return (result * sign);
}
