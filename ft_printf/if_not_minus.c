/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_not_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:12:19 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/12 12:12:20 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		if_n_min_add2(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	len = 0;
	accur = parse_accuracy(run, num);
	flag = parse_flags(ft_atoi_n(num), run, num);
	if ((is_n(run->sp, run->length) == 1
		|| run->sp->cd) && ft_atoi_n(num) < 0)
		num = num + 1;
	width = parse_wid(run, num, accur, flag);
	if (run->flags->zero)
	{
		if (!run->sp->p)
			len = ft_pt_zero(ft_realloc_cat(flag, width), accur, num, run);
		else
			len = pt_min_p(ft_realloc_cat(flag, accur), width, num, run);
	}
	else if (!run->sp->p)
		len = ft_puttext(ft_realloc_cat(width, flag), accur, num, run);
	return (len);
}

int		if_n_min_add(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	accur = parse_accuracy(run, num);
	flag = parse_flags(ft_atoi_n(num), run, num);
	if ((is_n(run->sp, run->length) == 1
		|| run->sp->cd) && ft_atoi_n(num) < 0)
		num = num + 1;
	width = parse_wid(run, num, accur, flag);
	if (run->flags->minus || run->pr->dot_number > run->width->number)
		len = pt_min_p(ft_realloc_cat(flag, accur), width, num, run);
	else
		len = pt_min_p(ft_realloc_cat(width, flag), accur, num, run);
	return (len);
}

int		if_not_minus(t_lst *run, char *num)
{
	int		len;

	len = 0;
	if (run->flags->zero)
		len = if_n_min_add2(run, num);
	else if (!run->sp->p)
		len = if_n_min_add2(run, num);
	else
		len = if_n_min_add(run, num);
	return (len);
}
