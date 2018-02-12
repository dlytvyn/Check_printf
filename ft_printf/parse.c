/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:50:28 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:49:32 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*parse_flags(intmax_t num, t_lst *run, char *res)
{
	char	*space;

	space = NULL;
	if (run->flags->plus && num >= 0 && (run->sp->d || run->sp->i))
		space = ft_strdup("+");
	else if (run->flags->space && num >= 0 && is_n(run->sp, run->length) == 1)
		space = ft_strdup(" ");
	else if (run->flags->cell)
	{
		space = (run->sp->o && res[0] != '0') ? ft_strdup("0") : space;
		space = (run->sp->co && res[0] != '0') ? ft_strdup("0") : space;
		space = (run->sp->x == 1 && num != 0) ? ft_strdup("0x") : space;
		space = (run->sp->cx == 1 && num != 0) ? ft_strdup("0X") : space;
	}
	else if (run->sp->p)
		space = ft_strdup("0x");
	else if (num < 0 && (run->sp->d || run->sp->i || run->sp->cd))
		space = ft_strdup("-");
	return (space);
}

char		*parse_accuracy(t_lst *run, char *num)
{
	int		ac;
	int		size;
	int		number;
	char	*temp;

	temp = NULL;
	if (run->pr->dot_number >= 0
		&& is_n(run->sp, run->length) != 4 && !run->sp->proc)
	{
		if (run->pr->dot_number > 0)
		{
			ac = run->pr->dot_number;
			size = ft_strlen(num);
			((run->sp->o || run->sp->co)
				&& run->pr->dot_number >= 0 && run->flags->cell) ? size++ : 1;
			number = ft_atoi(num);
			size = (number >= 0) ? size : size - 1;
			if (ac - size > 0)
			{
				temp = ft_strnew(ac - size);
				temp = ft_memset(temp, '0', ac - size);
			}
		}
	}
	return (temp);
}

char		*parse_wid(t_lst *run, char *num, char *accur, char *flag)
{
	int		width;
	char	*temp;
	int		len;

	temp = NULL;
	len = (num[0] == '\0' && run->sp->c) ? 1 : ft_len(num);
	if (run->width->number >= 0)
	{
		width = run->width->number;
		width = width - (len + ft_len(accur) + ft_len(flag));
		if (width > 0)
		{
			temp = ft_strnew(width);
			temp = ft_memset(temp, (run->flags->zero
				&& !run->flags->minus && (!run->pr->fl
				|| run->pr->dot_number < 0 || type(run))) ? '0' : ' ', width);
		}
	}
	return (temp);
}
