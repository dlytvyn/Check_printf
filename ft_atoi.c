/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:29:19 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/08/28 17:29:30 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					add;
	unsigned long int	res;

	res = 0;
	add = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		add = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res *= 10;
		res += str[i] - '0';
		if (res >= 9223372036854775807 && add == 1)
			return (-1);
		else if (res > 9223372036854775807 && add == -1)
			return (0);
		else
			i++;
	}
	return ((int)(res * add));
}
