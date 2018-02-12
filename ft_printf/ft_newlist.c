/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:59:12 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:36:27 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

t_lst	*ft_newlst(void)
{
	t_lst	*elem;

	elem = (t_lst*)malloc(sizeof(t_lst));
	elem->flags = (t_flags*)malloc(sizeof(t_flags));
	elem->width = (t_width*)malloc(sizeof(t_width));
	elem->pr = (t_pr*)malloc(sizeof(t_pr));
	elem->length = (t_length*)malloc(sizeof(t_length));
	elem->sp = (t_sp*)malloc(sizeof(t_sp));
	elem->color = (t_color*)malloc(sizeof(t_color));
	elem->flags = zero_to_flags(elem->flags);
	elem->width->number = 0;
	elem->pr = zero_to_precision(elem->pr);
	elem->length = zero_to_length(elem->length);
	elem->sp = zero_to_specifier(elem->sp);
	elem->color = zero_to_color(elem->color);
	elem->text = ft_strdup("");
	elem->wrong = ft_strdup("");
	return (elem);
}
