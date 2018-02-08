/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:41:42 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/10 11:41:44 by dlytvyn          ###   ########.fr       */
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

t_width		*zero_to_width(t_width *run)
{
	run->number = -1;
	run->star = 0;
	return (run);
}

t_precision	*zero_to_precision(t_precision *run)
{
	run->dot_number = -1;
	run->fl = 0;
	run->dot_star = 0;
	return (run);
}

t_length	*zero_to_length(t_length *run)
{
	run->h = 0;
	run->hh = 0;
	run->j = 0;
	run->L = 0;
	run->l = 0;
	run->ll = 0;
	run->z = 0;
	return (run);
}

t_specifier	*zero_to_specifier(t_specifier *run)
{
	run->c = 0;
	run->C = 0;
	run->D = 0;
	run->d = 0;
	run->i = 0;
	run->O = 0;
	run->o = 0;
	run->p = 0;
	run->proc = 0;
	run->s = 0;
	run->S = 0;
	run->u = 0;
	return (run);
}
