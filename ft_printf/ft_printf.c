/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:57:36 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:40:50 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int		if_minus(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	flag = parse_flags(ft_atoi_n(num), run, num);
	accur = parse_accuracy(run, num);
	if (ft_atoi_n(num) < 0)
		num = num + 1;
	width = parse_wid(run, num, accur, flag);
	len = ft_text_m(ft_realloc_cat(flag, accur), width, num, run);
	return (len);
}

int				ft_align(t_lst *run, char *num)
{
	if (ft_text(run) && run->pr->fl)
		num = pr_char(run, num);
	if (run->sp->s && run->pr->fl)
	{
		if (run->pr->yes == 0 || run->pr->dot_number == 0)
		{
			free(num);
			num = ft_strdup("");
		}
	}
	if (ft_atoi(num) == 0 && run->pr->fl && ft_numeric(run))
	{
		free(num);
		num = ft_strdup("");
	}
	if (run->flags->minus)
		return (if_minus(run, num));
	else
		return (if_not_minus(run, num));
}

int				ft_printf(const char *format, ...)
{
	va_list			args;
	char			*form;
	t_lst			*head;
	int				num;

	num = 0;
	head = NULL;
	va_start(args, format);
	form = (char*)format;
	while (*form)
	{
		head = ft_newlst();
		form = ft_format(form, head, args);
		num += ft_typing(args, head);
		clear_struct(head);
		free(head);
	}
	va_end(args);
	return (num);
}
