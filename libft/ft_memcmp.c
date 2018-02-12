/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:26:11 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 12:26:12 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*text1;
	unsigned char	*text2;
	size_t			i;

	i = 0;
	text1 = (unsigned char *)s1;
	text2 = (unsigned char *)s2;
	while (i < n)
	{
		if (text1[i] != text2[i])
			return (text1[i] - text2[i]);
		i++;
	}
	return (0);
}
