/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:58:16 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 14:58:16 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*array;
	int				i;
	unsigned char	sign;

	array = (unsigned char *)s;
	sign = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (array[i] == sign)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}
