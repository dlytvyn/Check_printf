/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:22:30 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/08/29 15:22:31 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
		if (i >= n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
