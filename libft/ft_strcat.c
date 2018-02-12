/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 19:23:41 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/08/29 19:23:42 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*src;
	char	*dest;
	int		counter;
	int		counter2;

	dest = (char *)s1;
	src = (char *)s2;
	counter = 0;
	counter2 = 0;
	while (dest[counter] != '\0')
		counter++;
	while (src[counter2] != '\0')
	{
		dest[counter++] = src[counter2++];
	}
	dest[counter] = '\0';
	return (s1);
}
