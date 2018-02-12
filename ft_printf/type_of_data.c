/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:48:56 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:56:18 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*num_di(va_list args, t_length *run, t_sp *spec)
{
	char	*res;

	if (run->z == 1)
		res = ft_itoa_base_pt(va_arg(args, size_t));
	else if (run->j == 1)
		res = ft_itoa_base_pt(va_arg(args, intmax_t));
	else if (run->ll)
		res = ft_itoa_base_pt(va_arg(args, long long int));
	else if (run->l == 1)
		res = ft_itoa_base_pt(va_arg(args, long int));
	else if (run->h == 1)
		res = ft_itoa_base_pt((short int)va_arg(args, int));
	else if (run->hh == 1)
		res = ft_itoa_base_pt((signed char)va_arg(args, int));
	else if (run->cl == 1)
		res = ft_ib(va_arg(args, int64_t), base(spec), spec);
	else
		res = ft_itoa_base_pt(va_arg(args, int));
	return (res);
}

char		*num_rest(va_list args, t_length *run, t_sp *spec)
{
	char	*res;

	if (run->z == 1)
		res = ft_ib(va_arg(args, size_t), base(spec), spec);
	else if (run->j == 1)
		res = ft_ib(va_arg(args, uintmax_t), base(spec), spec);
	else if (run->ll)
		res = ft_ib(va_arg(args, unsigned long long int), base(spec), spec);
	else if (run->l == 1)
		res = ft_ib((size_t)va_arg(args, unsigned long int), base(spec), spec);
	else if (run->h == 1)
		res = ft_ib((unsigned short int)va_arg(args, int), base(spec), spec);
	else if (run->hh == 1)
		res = ft_ib((unsigned char)va_arg(args, int), base(spec), spec);
	else if (run->cl == 1)
		res = ft_ib(va_arg(args, int64_t), base(spec), spec);
	else
		res = ft_ib(va_arg(args, unsigned int), base(spec), spec);
	return (res);
}

char		*num_dou(va_list args, t_sp *spec, t_flags *flag)
{
	char	*res;

	res = NULL;
	if (spec->cd)
		res = ft_itoa_base_pt(va_arg(args, long int));
	else if (spec->co && flag->cell)
		res = ft_ib(va_arg(args, unsigned long int), base(spec), spec);
	else if (spec->co)
		res = ft_ib(va_arg(args, unsigned long int), base(spec), spec);
	else if (spec->cu)
		res = ft_ib(va_arg(args, unsigned long int), base(spec), spec);
	return (res);
}

char		*add_text(char *form, t_lst *run)
{
	run->text = ft_realloc(run->text, ft_strlen(run->text) + 1);
	run->text = ft_strncat(run->text, form, 1);
	form++;
	return (form);
}

char		*ft_format(char *form, t_lst *run, va_list args)
{
	int	thing;

	thing = 0;
	while (*form && *form != '%')
	{
		if (*form == '{')
			form = get_color(form, run->color);
		if (*form && *form != '%')
			form = add_text(form, run);
	}
	if (*form == '%')
		form++;
	while (*form && thing == 0 && *form != '\n')
	{
		form = ft_get_flags(form, run->flags);
		form = gt_wd(form, run->width, args, run->flags);
		form = ft_get_precision(form, run->pr, args);
		form = ft_get_length(form, run->length);
		thing = ft_get_specifier(form, run->sp);
		form = ((thing == 0) ? ft_wrong(form, run) : form);
		form++;
		if (run->wrong[0])
			break ;
	}
	return (form);
}
