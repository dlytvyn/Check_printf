/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:26:06 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/22 13:26:07 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int			active_bits(unsigned int c)
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

void    size_till_11(unsigned int v)
{
    unsigned char	octet;
    unsigned char   o2;
    unsigned char   o1;
    int             mask1;
    
    mask1 =  49280;
    o1 = ((v >> 6) << 27) >> 27;
    o2 = (v << 26) >> 26;
    octet = (mask1 >> 8) | o1;
    write(1, &octet, 1);
    octet = ((mask1 << 24) >> 24) | o2;
    write(1, &octet, 1);
}

void    size_till_16(unsigned int v)
{
    unsigned char   octet;
    unsigned char   o3;
    unsigned char   o2;
    unsigned char   o1;
    int             mask2; 
    
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

void    size_after_16(unsigned int v)
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
    octet = (mask3 >> 24) | o1;
    write(1, &octet, 1);
    octet = ((mask3 << 8) >> 24) | o2;
    write(1, &octet, 1);
    octet = ((mask3 << 16) >> 24) | o3;
    write(1, &octet, 1);
    octet = ((mask3 << 24) >> 24) | o4;
    write(1, &octet, 1);
}

void    size_till_7(unsigned int v)
{
    unsigned char octet;

    octet = v;
    write(1, &octet, 1);
}

int     byte_num(int size)
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

int     unic_sn(wchar_t *array, int num)
{
	int				i;
	unsigned int	v;
	int				size;
    int             res;

	i = 0;
    res = 0;
	while (array[i] && num > 0)
	{
        v = array[i];
        size = active_bits(v);
        if (MB_CUR_MAX <= 1 && (size  > 7))
        {
            size_till_7(v);
            res++;
            num--;
        }
        else if (num - byte_num(size) >= 0)
        {
            res += byte_num(size);
            num -= byte_num(size);
            if (size <= 7)
                size_till_7(v);
            else if (size <= 11)
                size_till_11(v);
            else if (size <= 16)
                size_till_16(v);
            else
                size_after_16(v);
        }
		i++;
	}
    return (res);
}

int     unic_s(wchar_t *array)
{
	int				i;
	unsigned int	v;
	int				size;
    int             res;

	i = 0;
    res = 0;
	while (array[i])
	{
        v = array[i];
        size = active_bits(v);
        if (MB_CUR_MAX <= 1 && (size  > 7))
        {
            size_till_7(v);
            res++;
        }
        else
        {
            res += byte_num(size);
            if (size <= 7)
                size_till_7(v);
            else if (size <= 11)
                size_till_11(v);
            else if (size <= 16)
                size_till_16(v);
            else
                size_after_16(v);
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
    else if (MB_CUR_MAX <= 1 && (size  > 7))
    {
        size_till_7(v);
        return (1);
    }
    else  if (size <= 11)
        size_till_11(v);
    else  if (size <= 16)
        size_till_16(v);
    else
        size_after_16(v);
    return (byte_num(size));
}

int     length_s(wchar_t *ar)
{
    int size;
    int bits;
    int i;

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

int     length_s_one(wchar_t *ar)
{
    int bits;
    int i;

    i = 0;
    bits = 0;
    while (ar[i])
    {
        bits++;
        i++;
    }
    return (bits);
}

int     length_c(wchar_t ar)
{
    int size;

    size = active_bits(ar);
    return (byte_num(size));
}

int     ulen_lim(int num, wchar_t *ar)
{
    int size;
    int byte;
    int res;
    int i;

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