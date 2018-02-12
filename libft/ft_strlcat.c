/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:14:34 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/30 13:14:36 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = ft_strlen(dst);
	if (dstsize > l)
		ft_strncat(dst, src, (dstsize - l - 1));
	if (dstsize < l)
		return (dstsize + ft_strlen(src));
	else
		return (l + ft_strlen(src));
}
