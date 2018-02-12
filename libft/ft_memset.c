/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:48:24 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/25 18:48:25 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*array;
	unsigned char	sign;
	size_t			i;

	i = 0;
	array = (unsigned char*)b;
	sign = (unsigned char)c;
	while (i < len)
		array[i++] = sign;
	return (b);
}
