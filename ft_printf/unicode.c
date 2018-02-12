/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:26:06 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:53:27 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	unic_sn_add(int size, unsigned int v)
{
	if (size <= 7)
		size_till_7(v);
	else if (size <= 11)
		size_till_11(v);
	else if (size <= 16)
		size_till_16(v);
	else
		size_after_16(v);
}

int		unic_sn(wchar_t *array, int num)
{
	int				i;
	unsigned int	v;
	int				size;
	int				res;

	i = 0;
	res = 0;
	while (array[i] && num > 0)
	{
		v = array[i++];
		size = active_bits(v);
		if (MB_CUR_MAX <= 1 && (size > 7))
		{
			size_till_7(v);
			res++;
			num--;
		}
		else if (num - byte_num(size) >= 0)
		{
			res += byte_num(size);
			num -= byte_num(size);
			unic_sn_add(size, v);
		}
	}
	return (res);
}

void	unic_s_add(int size, unsigned int v)
{
	if (size <= 7)
		size_till_7(v);
	else if (size <= 11)
		size_till_11(v);
	else if (size <= 16)
		size_till_16(v);
	else
		size_after_16(v);
}

int		unic_s(wchar_t *array)
{
	int				i;
	unsigned int	v;
	int				size;
	int				res;

	i = 0;
	res = 0;
	while (array[i])
	{
		v = array[i];
		size = active_bits(v);
		if (MB_CUR_MAX <= 1 && (size > 7))
		{
			size_till_7(v);
			res++;
		}
		else
		{
			res += byte_num(size);
			unic_s_add(size, v);
		}
		i++;
	}
	return (res);
}

int		unic_c(wchar_t ar)
{
	unsigned int	v;
	int				size;

	v = ar;
	size = active_bits(v);
	if (size <= 7)
		size_till_7(v);
	else if (MB_CUR_MAX <= 1 && (size > 7))
	{
		size_till_7(v);
		return (1);
	}
	else if (size <= 11)
		size_till_11(v);
	else if (size <= 16)
		size_till_16(v);
	else
		size_after_16(v);
	return (byte_num(size));
}
