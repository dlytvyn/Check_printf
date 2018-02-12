/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:22:30 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:24:08 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_realloc_cat(char *array, char *source)
{
	char	*res;
	int		size;

	res = NULL;
	size = ft_len(array) + ft_len(source);
	if (size == 0)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (array)
		ft_strcpy(res, array);
	if (source)
		ft_strcat(res, source);
	free(array);
	free(source);
	return (res);
}
