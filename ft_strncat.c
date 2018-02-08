/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:07:18 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 13:07:19 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*src;
	char	*dest;
	int		counter;
	size_t	counter2;

	dest = (char *)s1;
	src = (char *)s2;
	counter = 0;
	counter2 = 0;
	while (dest[counter] != '\0')
		counter++;
	while (counter2 < n && src[counter2])
	{
		dest[counter++] = src[counter2++];
	}
	dest[counter] = '\0';
	return (s1);
}
