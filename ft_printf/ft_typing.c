/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:10:42 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/12 12:10:42 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_typing_add(va_list args, t_lst *head, char *res)
{
	if (is_n(head->sp, head->length) == 1)
		res = num_di(args, head->length, head->sp);
	else if (is_n(head->sp, head->length) == 2)
		res = num_rest(args, head->length, head->sp);
	else if (is_n(head->sp, head->length) == 3)
		res = num_dou(args, head->sp, head->flags);
	else if (is_n(head->sp, head->length) == 4)
		res = ft_char_type(args, head->sp, head->length);
	else if (is_n(head->sp, head->length) == 5)
		res = ft_pointer(res, args, head);
	else if (is_n(head->sp, head->length) == 6)
		res = ft_strdup("%");
	return (res);
}

int		ft_typing(va_list args, t_lst *head)
{
	char	*res;
	int		size;

	res = NULL;
	size = 0;
	ft_reset(head->color);
	if (head->text[0])
		write(1, head->text, ft_strlen(head->text));
	print_color(head->color);
	if (is_n(head->sp, head->length) != 0 && is_n(head->sp, head->length) != 7)
		res = ft_typing_add(args, head, res);
	else if (is_n(head->sp, head->length) == 7)
		size += char_cs(args, head);
	else if (head->wrong[0])
		res = ft_strdup(head->wrong);
	else
		return (ft_strlen(head->text));
	if ((ft_uni_type(head->sp, head->length) == 0 || MB_CUR_MAX <= 1) && res)
		size += ft_align(head, res);
	size += ft_len(head->text);
	(head->sp->proc) ? free(res) : 1;
	(head->wrong[0]) ? free(res) : 1;
	(ft_numeric(head) == 1 || head->sp->p) ? free(res) : 1;
	(head->sp->s && !head->length->l) ? free(res) : 1;
	return (size);
}
