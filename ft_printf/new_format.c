/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:41:42 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:34:28 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

t_flags		*zero_to_flags(t_flags *run)
{
	run->cell = 0;
	run->minus = 0;
	run->plus = 0;
	run->space = 0;
	run->zero = 0;
	return (run);
}

t_pr		*zero_to_precision(t_pr *run)
{
	run->dot_number = -1;
	run->fl = 0;
	run->yes = 0;
	return (run);
}

t_length	*zero_to_length(t_length *run)
{
	run->h = 0;
	run->hh = 0;
	run->j = 0;
	run->cl = 0;
	run->l = 0;
	run->ll = 0;
	run->z = 0;
	return (run);
}

t_color		*zero_to_color(t_color *run)
{
	run->blu = 0;
	run->cya = 0;
	run->gre = 0;
	run->mag = 0;
	run->re = 0;
	run->rese = 0;
	run->yel = 0;
	run->whi = 0;
	return (run);
}

t_sp		*zero_to_specifier(t_sp *run)
{
	run->c = 0;
	run->cc = 0;
	run->cd = 0;
	run->d = 0;
	run->i = 0;
	run->co = 0;
	run->o = 0;
	run->p = 0;
	run->proc = 0;
	run->s = 0;
	run->cs = 0;
	run->u = 0;
	run->cu = 0;
	run->x = 0;
	run->cx = 0;
	run->b = 0;
	return (run);
}
