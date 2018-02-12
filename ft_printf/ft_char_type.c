/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:54:30 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:33:44 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_char_type(va_list args, t_sp *spec, t_length *length)
{
	char	*res;
	char	*temp;

	res = NULL;
	if (spec->c && !length->l)
	{
		res = ft_strnew(1);
		res[0] = (va_arg(args, int));
	}
	else if (spec->s == 1 && !length->l)
	{
		temp = (va_arg(args, char*));
		if (temp == NULL)
			res = ft_strdup("(null)");
		else
			res = ft_strdup(temp);
	}
	return (res);
}
