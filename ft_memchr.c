/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:10:43 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 12:10:43 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*array;
	size_t			i;
	unsigned char	sign;

	array = (unsigned char *)s;
	sign = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (array[i] == sign)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
