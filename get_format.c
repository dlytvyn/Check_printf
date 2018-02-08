/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:26:14 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/11 12:26:15 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

const char	*ft_get_flags(const char *form, t_flags *run)
{
	(*form == '-') ? run->minus = 1 : 0;
	(*form == '+') ? run->plus = 1 : 0;
	(*form == ' ') ? run->space = 1 : 0;
	(*form == '#') ? run->cell = 1 : 0;
	(*form == '0') ? run->zero = 1 : 0;
	return (form);
}

const char	*ft_get_width(const char *form, t_width *run)
{
	if (*form >= '1' && *form <= '9')
	{
		if (*form >= '1' && *form <= '9')
			run->number = ft_atoi(form);
        while (*form >= '0' && *form <= '9')
            form++;
        form--;
	}
	else if (*form == '*')
		run->star = 1;
	return (form);
}

const char	*ft_get_precision(const char *form, t_precision *run)
{
	if (*form == '.')
	{
        run->dot_number = 0;
		form++;
		run->fl = 1;
		if (*form >= '1' && *form <= '9')
		{
            run->dot_number = ft_atoi(form);
			while (*form >= '0' && *form <= '9')
                form++;
		}
		else if (*form == '*')
			run->dot_star = 1;
        form--;
	}
	return (form);
}

const char	*ft_get_length(const char *form, t_length *run)
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
	(*form == 'L') ? run->L = 1 : 0;
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

int		ft_get_specifier(const char *form, t_specifier *run)
{
	int count;

	count = 0;
	(*form == 's') ? run->s = 1 : count++;
	(*form == 'S') ? run->S = 1 : count++;
	(*form == 'p') ? run->p = 1 : count++;
	(*form == 'd') ? run->d = 1 : count++;
	(*form == 'D') ? run->D = 1 : count++;
	(*form == 'i') ? run->i = 1 : count++;
	(*form == 'o') ? run->o = 1 : count++;
	(*form == 'O') ? run->O = 1 : count++;
	(*form == 'u') ? run->u = 1 : count++;
	(*form == 'U') ? run->U = 1 : count++;
	(*form == 'x') ? run->x = 1 : count++;
	(*form == 'X') ? run->X = 1 : count++;
	(*form == 'c') ? run->c = 1 : count++;
	(*form == 'C') ? run->C = 1 : count++;
	(*form == '%') ? run->proc = 1 : count++;
	if (count == 15)
		return (0);
	else
		return (1);
}

const char	*ft_wrong(const char *form, t_lst *run)
{
	char	*comp;

	comp = ft_strdup("sSpdDiouUxXcC%-+ #0.123456789lLhjz");
	if (ft_strchr(comp, *form) == 0)
	{
        run->wrong = ft_realloc(run->wrong, ft_strlen(run->wrong) + 1);
        run->wrong = ft_strncat(run->wrong, form, 1);
	}
    ft_strdel(&comp);
	return (form);
}
