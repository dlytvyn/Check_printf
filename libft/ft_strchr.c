/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:05:53 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 14:05:54 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*array;
	size_t			i;
	unsigned char	sign;

	array = (unsigned char *)s;
	sign = (unsigned char)c;
	i = 0;
	while (array[i])
	{
		if (array[i] == sign)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == '\0' && sign == '\0')
		return ((char*)(s + i));
	return (NULL);
}
