/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 10:00:21 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/08/29 10:00:22 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int index;
	int index2;
	int index3;

	index = 0;
	index2 = 0;
	index3 = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[index] != '\0')
	{
		index3 = 0;
		index2 = index;
		while (haystack[index2] == needle[index3])
		{
			if (needle[index3 + 1] == '\0')
			{
				return (char *)(&haystack[index]);
			}
			index2++;
			index3++;
		}
		index++;
	}
	return (0);
}
