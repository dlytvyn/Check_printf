/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:56:20 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:32:20 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

ssize_t	ft_atoi_n(const char *str)
{
	size_t		i;
	int			add;
	ssize_t		res;

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
		if (res > 9223372036854775807 && add == 1)
			return (-1);
		else if (res > 9223372036854775807 && add == -1)
			return (0);
		else
			i++;
	}
	return ((res * add));
}
