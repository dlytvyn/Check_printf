/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:33:58 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/08/29 22:33:59 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	q;

	i = 0;
	if (needle[0] == '\0')
		return (char*)(haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		q = 0;
		if (haystack[i] == needle[j])
		{
			q = i;
			while (needle[j] != '\0' && haystack[q] == needle[j] && q < len)
			{
				if (needle[j + 1] == '\0' && needle[j] == haystack[q])
					return (char*)(haystack + i);
				q++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
