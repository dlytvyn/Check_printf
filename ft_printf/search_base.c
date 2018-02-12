/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:03:22 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:53:47 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		base(t_sp *spec)
{
	if (spec->d || spec->i || spec->u || spec->cd || spec->cu)
		return (10);
	else if (spec->o || spec->co)
		return (8);
	else if (spec->x == 1 || spec->cx == 1)
		return (16);
	else if (spec->b)
		return (2);
	else
		return (10);
}
