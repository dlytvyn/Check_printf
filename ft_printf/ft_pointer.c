/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:01:34 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:37:07 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_pointer(char *res, va_list args, t_lst *head)
{
	char	*temp;

	temp = ft_ib((size_t)va_arg(args, void*), 16, head->sp);
	if (!head->pr->fl || temp[0] != '0')
		res = temp;
	else
		res = ft_strdup("");
	return (res);
}
