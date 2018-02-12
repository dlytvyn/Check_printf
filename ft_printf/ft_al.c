/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:30:00 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:12:36 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int			is_n(t_sp *s, t_length *len)
{
	if (s->d == 1 || s->i == 1)
		return (1);
	else if (s->o == 1 || s->u == 1 || s->x == 1 || s->cx == 1 || s->b)
		return (2);
	else if (s->cd == 1 || s->co == 1 || s->cu == 1)
		return (3);
	else if ((s->c == 1 || s->s == 1) && !len->l)
		return (4);
	else if (s->cc == 1 || s->cs == 1)
		return (7);
	else if ((s->c == 1 || s->s == 1) && len->l)
		return (7);
	else if (s->p == 1)
		return (5);
	else if (s->proc == 1)
		return (6);
	else
		return (0);
}

int			type(t_lst *run)
{
	t_sp *spec;

	spec = run->sp;
	if (is_n(spec, run->length) == 4 || is_n(spec, run->length) == 6)
		return (1);
	else if (is_n(spec, run->length) == 7 || is_n(spec, run->length) == 0)
		return (1);
	else
		return (0);
}

int			ft_text(t_lst *run)
{
	t_sp	*spec;

	spec = run->sp;
	if (spec->cs || spec->s)
		return (1);
	else
		return (0);
}

int			ft_numeric(t_lst *run)
{
	t_sp	*spec;

	spec = run->sp;
	if (spec->x || spec->cx || spec->d || spec->cd)
		return (1);
	else if (spec->i || spec->u || spec->cu || spec->o || spec->co)
		return (1);
	else
		return (0);
}

int			ft_uni_type(t_sp *spec, t_length *len)
{
	if (spec->cc || (spec->c && len->l))
		return (1);
	else if (spec->cs || (spec->s && len->l))
		return (1);
	else
		return (0);
}
