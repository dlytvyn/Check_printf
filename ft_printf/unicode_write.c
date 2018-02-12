/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:48:33 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 18:48:34 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		active_bits(unsigned int c)
{
	int		res;
	int		i;

	i = 1;
	res = 0;
	while (i != 33)
	{
		if (c & 1)
			res = i;
		c >>= 1;
		i++;
	}
	return (res);
}

void	size_till_11(unsigned int v)
{
	unsigned char	octet;
	unsigned char	o2;
	unsigned char	o1;
	int				mask1;

	mask1 = 49280;
	o1 = ((v >> 6) << 27) >> 27;
	o2 = (v << 26) >> 26;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void	size_till_16(unsigned int v)
{
	unsigned char	octet;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	int				mask2;

	mask2 = 14712960;
	o1 = ((v >> 12) << 28) >> 28;
	o2 = ((v >> 6) << 26) >> 26;
	o3 = (v << 26) >> 26;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
}

void	size_after_16(unsigned int v)
{
	unsigned char octet;
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o1 = ((v >> 18) << 29) >> 29;
	o2 = ((v >> 12) << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o4 = (v << 26) >> 26;
	octet = (MASK3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((MASK3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((MASK3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((MASK3 << 24) >> 24) | o4;
	write(1, &octet, 1);
}

void	size_till_7(unsigned int v)
{
	unsigned char octet;

	octet = v;
	write(1, &octet, 1);
}
