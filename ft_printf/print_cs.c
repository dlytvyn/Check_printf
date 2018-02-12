/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_CS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:55:15 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:53:11 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		c_min(wchar_t c, t_lst *run)
{
	int	i;
	int	h;
	int	res;

	i = 0;
	res = unic_c(c);
	h = run->width->number - length_c(c);
	while (i < h)
	{
		ft_putchar((run->flags->zero) ? '0' : ' ');
		i++;
	}
	res += i;
	return (res);
}

int		c_n_min(wchar_t c, t_lst *run)
{
	int	i;
	int	h;
	int	res;

	i = 0;
	h = run->width->number - length_c(c);
	while (i < h)
	{
		ft_putchar((run->flags->zero) ? '0' : ' ');
		i++;
	}
	res = unic_c(c);
	res += i;
	return (res);
}

int		s_min(wchar_t *s, t_lst *run)
{
	int	i;
	int	h;
	int	res;

	i = 0;
	res = 0;
	if (run->pr->dot_number >= 0)
		res = unic_sn(s, run->pr->dot_number);
	else
		res = unic_s(s);
	if (run->pr->dot_number >= 0)
		h = run->width->number - run->pr->dot_number;
	else
		h = run->width->number - length_s(s);
	while (i < h)
	{
		ft_putchar(' ');
		i++;
	}
	res += i;
	return (res);
}

int		s_n_min(wchar_t *s, t_lst *run)
{
	int	i;
	int	h;
	int	res;

	i = 0;
	res = 0;
	if (run->pr->dot_number >= 0 || run->pr->fl)
		h = run->width->number - ulen_lim(run->pr->dot_number, s);
	else if (MB_CUR_MAX > 1)
		h = run->width->number - length_s(s);
	else
		h = run->width->number - length_s_one(s);
	while (i < h)
	{
		ft_putchar((run->flags->zero) ? '0' : ' ');
		i++;
	}
	if (run->pr->dot_number >= 0)
		res = unic_sn(s, run->pr->dot_number);
	else if (!run->pr->fl)
		res = unic_s(s);
	res += i;
	return (res);
}

int		char_cs(va_list args, t_lst *run)
{
	wchar_t	c;
	wchar_t	*s;

	if ((run->sp->c && run->length->l) || run->sp->cc)
	{
		c = (va_arg(args, wint_t));
		if (run->flags->minus)
			return (c_min(c, run));
		else
			return (c_n_min(c, run));
	}
	else if ((run->sp->s == 1 && run->length->l) || run->sp->cs)
	{
		s = (va_arg(args, wchar_t*));
		if (s == NULL)
			s = L"(null)";
		if (run->flags->minus)
			return (s_min(s, run));
		else
			return (s_n_min(s, run));
	}
	return (1);
}
