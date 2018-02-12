/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:26:14 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:32:17 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_get_flags(char *form, t_flags *run)
{
	(*form == '-') ? run->minus = 1 : 0;
	(*form == '+') ? run->plus = 1 : 0;
	(*form == ' ') ? run->space = 1 : 0;
	(*form == '#') ? run->cell = 1 : 0;
	(*form == '0') ? run->zero = 1 : 0;
	return (form);
}

char	*gt_wd(char *form, t_width *run, va_list args, t_flags *f)
{
	if (*form == '*')
	{
		run->number = va_arg(args, int);
		if (run->number < 0)
		{
			run->number = -run->number;
			f->minus = 1;
		}
	}
	if (*form >= '1' && *form <= '9')
	{
		if (*form >= '0' && *form <= '9')
			run->number = ft_atoi(form);
		while (*form >= '0' && *form <= '9')
			form++;
		form--;
	}
	return (form);
}

char	*ft_get_precision(char *form, t_pr *run, va_list args)
{
	if (*form == '.')
	{
		run->yes = 0;
		form++;
		run->fl = 1;
		run->dot_number = 0;
		if (*form == '*')
		{
			run->dot_number = va_arg(args, int);
			run->yes = (run->dot_number != 0) ? 1 : 0;
			form++;
		}
		if (*form >= '0' && *form <= '9')
		{
			run->dot_number = ft_atoi(form);
			run->yes = (run->dot_number != 0) ? 1 : 0;
			while (*form >= '0' && *form <= '9')
				form++;
		}
		form--;
	}
	return (form);
}

char	*ft_get_length(char *form, t_length *run)
{
	if (*form == 'l')
	{
		run = zero_to_length(run);
		if (*(form + 1) == 'l')
		{
			run->ll = 1;
			form++;
		}
		else
			run->l = 1;
	}
	(*form == 'L') ? run->cl = 1 : 0;
	if (*form == 'h')
	{
		if (*(form + 1) == 'h')
		{
			run->hh = 1;
			form++;
		}
		else
			run->h = 1;
	}
	(*form == 'j') ? run->j = 1 : 0;
	(*form == 'z') ? run->z = 1 : 0;
	return (form);
}

int		ft_get_specifier(char *form, t_sp *run)
{
	int count;

	count = 0;
	(*form == 's') ? run->s = 1 : count++;
	(*form == 'S') ? run->cs = 1 : count++;
	(*form == 'p') ? run->p = 1 : count++;
	(*form == 'd') ? run->d = 1 : count++;
	(*form == 'D') ? run->cd = 1 : count++;
	(*form == 'i') ? run->i = 1 : count++;
	(*form == 'o') ? run->o = 1 : count++;
	(*form == 'O') ? run->co = 1 : count++;
	(*form == 'u') ? run->u = 1 : count++;
	(*form == 'U') ? run->cu = 1 : count++;
	(*form == 'x') ? run->x = 1 : count++;
	(*form == 'X') ? run->cx = 1 : count++;
	(*form == 'c') ? run->c = 1 : count++;
	(*form == 'C') ? run->cc = 1 : count++;
	(*form == 'b') ? run->b = 1 : count++;
	(*form == '%') ? run->proc = 1 : count++;
	if (count == 16)
		return (0);
	else
		return (1);
}
