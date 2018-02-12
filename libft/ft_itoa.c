/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:29:23 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/11/02 12:29:24 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	numsize(long long int n)
{
	int		counter;

	counter = 0;
	if (is_neg(n) == 1)
	{
		n = -n;
		counter++;
	}
	if (n == 0)
		counter++;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	long long	num;
	char		*res;
	int			i;
	int			size;
	int			add;

	num = n;
	size = numsize(num);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	res[size--] = '\0';
	if ((add = is_neg(num)))
		num *= (-1);
	while (size >= 0)
	{
		if (add == 1 && size == 0)
			res[size--] = '-';
		res[size--] = num % 10 + '0';
		num = num / 10;
	}
	return (res);
}
