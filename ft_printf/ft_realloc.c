/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:57:16 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:46:41 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	*ft_realloc(void *array, size_t size)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (array)
	{
		ft_bzero(res, size + 1);
		ft_strcpy(res, array);
		free(array);
	}
	return (res);
}
