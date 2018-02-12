/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:05:13 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 17:05:14 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*ft_itoa_base_pt(ssize_t n)
{
	size_t			num;
	char			*res;
	int				size;
	int				add;

	num = n;
	size = numsize(num);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	if ((add = is_neg(num)) == 1)
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
