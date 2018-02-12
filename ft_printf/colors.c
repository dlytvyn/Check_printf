/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:04:11 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:09:54 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void		ft_reset(t_color *col)
{
	char esc;

	esc = 27;
	if (col->rese)
	{
		write(1, &esc, 1);
		write(1, "[0m", 3);
		col->rese = 0;
	}
}

static void	print_colors_add(t_color *col)
{
	char esc;

	esc = 27;
	if (col->blu)
	{
		write(1, &esc, 1);
		write(1, "[34m", 4);
	}
	else if (col->mag)
	{
		write(1, &esc, 1);
		write(1, "[35m", 4);
	}
	else if (col->cya)
	{
		write(1, &esc, 1);
		write(1, "[36m", 4);
	}
	else if (col->whi)
	{
		write(1, &esc, 1);
		write(1, "[37m", 4);
	}
}

void		print_color(t_color *col)
{
	char esc;

	esc = 27;
	if (col->re)
	{
		write(1, &esc, 1);
		write(1, "[31m", 4);
	}
	else if (col->gre)
	{
		write(1, &esc, 1);
		write(1, "[32m", 4);
	}
	else if (col->yel)
	{
		write(1, &esc, 1);
		write(1, "[33m", 4);
	}
	else
		print_colors_add(col);
}
