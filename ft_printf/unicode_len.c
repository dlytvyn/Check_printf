/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:45:27 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 18:45:28 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		length_s(wchar_t *ar)
{
	int	size;
	int	bits;
	int	i;

	i = 0;
	bits = 0;
	while (ar[i])
	{
		size = active_bits(ar[i]);
		bits += byte_num(size);
		i++;
	}
	return (bits);
}

int		length_s_one(wchar_t *ar)
{
	int	bits;
	int	i;

	i = 0;
	bits = 0;
	while (ar[i])
	{
		bits++;
		i++;
	}
	return (bits);
}

int		length_c(wchar_t ar)
{
	int size;

	size = active_bits(ar);
	return (byte_num(size));
}

int		ulen_lim(int num, wchar_t *ar)
{
	int	size;
	int	byte;
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (ar[i] && num > 0)
	{
		size = active_bits(ar[i]);
		byte = byte_num(size);
		if (num - byte >= 0)
			res += byte;
		num -= byte;
		i++;
	}
	return (res);
}

int		byte_num(int size)
{
	if (size >= 0 && size <= 7)
		return (1);
	else if (size > 7 && size <= 11)
		return (2);
	else if (size > 11 && size <= 16)
		return (3);
	else
		return (4);
}
