/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:03:54 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/10 12:03:55 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	*ft_realloc(void *array, size_t size)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (array)
	{
		ft_strcpy(res, array);
		free(array);
	}
	return (res);
}

t_lst	*ft_newlst(void)
{
	t_lst	*elem;

	elem = (t_lst*)malloc(sizeof(t_lst));
	elem->flags = (t_flags*)malloc(sizeof(t_flags));
	elem->width = (t_width*)malloc(sizeof(t_width));
	elem->precision = (t_precision*)malloc(sizeof(t_precision));
	elem->length = (t_length*)malloc(sizeof(t_length));
	elem->specifier = (t_specifier*)malloc(sizeof(t_specifier));
	elem->flags = zero_to_flags(elem->flags);
	elem->width = zero_to_width(elem->width);
	elem->precision = zero_to_precision(elem->precision);
	elem->length = zero_to_length(elem->length);
	elem->specifier = zero_to_specifier(elem->specifier);
	elem->text = ft_strdup("");
	elem->next = NULL;
	return (elem);
}

const char	*ft_format(const char *form, t_lst *run)
{
	int	thing;

	while (*form)
	{
		thing = 0;
		while (*form && *form != '%')
		{
			run->text = ft_realloc(run->text, ft_strlen(run->text) + 1);
			run->text = ft_strncat(run->text, form, 1);
			form++;
		}
		if (*form == '%')
			form++;
		while (*form && thing == 0)
		{
			form = ft_get_flags(form, run->flags);
			form = ft_get_width(form, run->width);
			form = ft_get_precision(form, run->precision);
			form = ft_get_length(form, run->length);
			thing = ft_get_specifier(form, run->specifier);
			form++;
		}
        if (*form)
        {
            run->next = ft_newlst();
            run = run->next;
        }
	}
	return (form);
}

char	ft_spec(t_specifier *run)
{
	if (run->c == 1)
		return ('c');
	else if (run->C == 1)
		return ('C');
	else if (run->D == 1)
		return ('D');
	else if (run->d == 1)
		return ('d');
	else if (run->i == 1)
		return ('i');
	else if (run->O == 1)
		return ('O');
	else if (run->o == 1)
		return ('o');
	else if (run->p == 1)
		return ('p');
	else if (run->proc == 1)
		return ('%');
	else if (run->s == 1)
		return ('s');
	else if (run->S == 1)
		return ('S');
	else if (run->u == 1)
		return ('u');
	else
		return (0);
}

int		search_base(t_specifier *spec)
{
	if (spec->d || spec->i || spec->u || spec->D || spec->U)
		return (10);
	else if (spec->o || spec->O)
		return (8);
	else if (spec->x == 1 || spec->X == 1)
		return (16);
	else
		return (10);
}


char		*num_di(va_list args, t_length *run, t_specifier *spec, t_flags *flag)
{
	char	*res;

	if (run->h == 1)
		res = ft_itoa_base((unsigned short int)va_arg(args, int), search_base(spec), spec);
	else if (run->hh == 1)
		res = ft_itoa_base((unsigned char)va_arg(args, int), search_base(spec), spec);
	else if (run->j == 1)
		res = ft_itoa_base(va_arg(args, intmax_t), search_base(spec), spec);
	else if (run->L == 1)
		res = ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec);
	else if (run->l == 1)
		res = ft_itoa_base(va_arg(args, long int), search_base(spec), spec);
	else if (run->ll)
		res = ft_itoa_base(va_arg(args, long long int), search_base(spec), spec);
	else if (run->z == 1)
		res = ft_itoa_base(va_arg(args, size_t), search_base(spec), spec);
	else
		res = ft_itoa_base_pt(va_arg(args, int), search_base(spec), spec);
   // if (flag->minus && flag->plus && ft_atoi(res) > 0)
   //     res = ft_realloc_cat("+", res);
//	if (flag->minus && flag->space && ft_atoi(res) > 0)
  //      res = ft_realloc_cat(" ", res);
	return (res);
}

char		*num_rest(va_list args, t_length *run, t_specifier *spec, t_flags *flag)
{
	char	*res;

	res = ft_strdup("\0");
	if (run->h == 1)
		res = ft_realloc_cat(res, ft_itoa_base((unsigned short int)va_arg(args, int), search_base(spec), spec));
	else if (run->hh == 1)
		res = ft_realloc_cat(res, ft_itoa_base((unsigned char)va_arg(args, int), search_base(spec), spec));
	else if (run->j == 1)
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, uintmax_t), search_base(spec), spec));
	else if (run->L == 1)
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec));
	else if (run->l == 1)
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec));
	else if (run->ll)
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, unsigned long long int), search_base(spec), spec));
	else if (run->z == 1)
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, size_t), search_base(spec), spec));
	else
		res = ft_realloc_cat(res, ft_itoa_base(va_arg(args, int), search_base(spec), spec));
	return (res);
}

char		*num_DOU(va_list args, t_specifier *spec, t_flags *flag)
{
	char    *res;

	res = ft_strdup("\0");
	if (spec->D)
		res = ft_itoa_base(va_arg(args, long int), search_base(spec), spec);
	else if (spec->O && flag->cell)
		res = ft_realloc_cat("0", ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec));
    else if (spec->O)
        res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	else if (spec->U)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	return (res);
}

char	*push_space(char *res, int num, t_flags *flag)
{
	if (num > 0)
	{
		if (flag->plus && flag->minus == 0)
		{
			res = ft_strdup("+");
			res = ft_realloc(res, num);
		}
        else if (flag->space && flag->minus == 0)
        {
            res = ft_strdup(" ");
            res = ft_realloc(res, num);
        }
		else
			res = ft_strnew(num);
		num--;
		while (num >= 0)
		{
			res[num] = (flag->zero == 1 && flag->minus == 0) ? '0' : ' ';
			num--;
		}
	}
	else if (flag->plus)
		res = ft_strdup("+");
    else if (flag->space)
        res = ft_strdup(" ");
    else
        res = ft_strdup("");
	return (res);
}

char        *push_space2(char *res, int num, t_flags *flag, int nb)
{
    num = ((nb < 0 && (flag->minus || flag->zero))) ? num + 1 : num;
    num = (nb > 0 && ((flag->plus && flag->minus) || flag->space)) ? num - 1: num;
    if (num > 0)
    {
        res = ft_realloc(res, num);
        res = ft_memset(res, ' ', num);
        if (flag->plus && !flag->minus && nb > 0)
        {
            res = ft_memset(res, ' ', num - 1);
            res[num - 1] = '+';
        }
        else if (flag->space && nb > 0)
            res = ft_memset(res, ' ', num);
        if (flag->zero && !flag->minus)
        {
            res = ft_memset(res, '0', num);
            res[0] = (nb < 0) ? '-' : (flag->plus) ? '+' : '0';
        }
    }
    //else if (flag->plus)
    //    res = ft_strdup("+");
    //else if (flag->space)
    //    res = ft_strdup(" ");
    else
        res = ft_strdup("");
    return (res);
}

char		*ft_char_type(va_list args, t_specifier *spec, t_length *length)
{
	char *res;
	char ch;

	res = NULL;
	if (spec->c && !length->l)
		ch = (va_arg(args, int));
	//else if (spec->c && length->l)
		//ch = (va_arg(args, wint_t));
	else if (spec->s == 1 && !length->l)
		res = ft_strdup(va_arg(args, char*));
	//else if (spec->s == 1 && length->l)
		//res = ft_strdup(va_arg(args, wchar_t*));
	//else if (spec->C)
	//	res = 
	//else if (spec->S)
	//	res = 
	return (res);
}

int		is_num(t_specifier *spec)
{
	if (spec->d || spec->i)
		return (1);
	else if (spec->o || spec->u || spec->x || spec->X)
		return (2);
	else if (spec->D || spec->O || spec->U)
		return (3);
	else if (spec->c || spec->C || spec->s || spec->S)
		return (4);
	else if (spec->p)
		return (5);
	else if (spec->proc)
		return (6);
	else
		return (0);
}

char    *ft_neg(char *array)
{
    char *res;

    if (ft_atoi(array) < 0)
        res = ft_strdup(array + 1);
    else
        res = ft_strdup(array);
    free(array);
    return (res);
}



char	*ft_align(char *res, t_lst *head)             // flag "-"
{
	char	*spaces;
	int		i;

	spaces = NULL;
	if (head->flags->minus == 1)
	{
		i = 0;
		spaces = push_space2(spaces, ft_atoi(head->width->number) - ft_strlen(res), head->flags, ft_atoi(res));
        res = (head->flags->minus) ? res : ft_neg(res);
        res = (head->flags->plus && ft_atoi(res) > 0) ? ft_realloc_cat("+", res) : res;
        res = (head->flags->space && ft_atoi(res) > 0) ? ft_realloc_cat(" ", res) : res;
		res = ft_realloc(res, ft_strlen(res) + ft_strlen(spaces));
		res = ft_strcat(res, spaces);
	}
	else
	{
		i = 1;
		spaces = push_space2(spaces, ft_atoi(head->width->number) - ft_strlen(res), head->flags, ft_atoi(res));
        res = (head->flags->minus || head->flags->zero) ? ft_neg(res) : res;
        //res = (head->flags->plus && ft_atoi(res) > 0) ? ft_realloc_cat("+", res) : res;
		spaces = ft_realloc(spaces, ft_strlen(res) + ft_strlen(spaces));
		res = ft_strcat(spaces, res);
	}
	//return ((i == 1) ? spaces : res);
    return (res);
}

int		ft_typing(va_list args, t_lst *head)
{
	char *res;
	char *final;

	res = NULL;
	if (head->text[0])
		ft_putstr(head->text);
	if (is_num(head->specifier) == 1)
		res = num_di(args, head->length, head->specifier, head->flags);
	else if (is_num(head->specifier) == 2)
		res = num_rest(args, head->length, head->specifier, head->flags);
	else if (is_num(head->specifier) == 3)
		res = num_DOU(args, head->specifier, head->flags);
	else if (is_num(head->specifier) == 4)
		res = ft_char_type(args, head->specifier, head->length);
	else if (is_num(head->specifier) == 5)
	{
		ft_putstr("0x");
		res = ft_itoa_base_pt((size_t)va_arg(args, void*), 16, head->specifier);
	}
	else if (is_num(head->specifier) == 6)
		res = ft_strdup("%");
	else
		return (ft_strlen(head->text));
	final = ft_align(res, head);
	ft_putstr(final);
	return (ft_strlen(final));
}

int		ft_printf(const char *format, ...)
{
	va_list			args;
	const char		*form;
	t_lst			*head;
	t_lst			*run;
	int				num;

	head = NULL;
	head = ft_newlst();
	run = head;
	va_start(args, format);
	form = format;
	form = ft_format(form, run);
	while (head)
	{
		num = ft_typing(args, head);
		head = head->next;
	}
	va_end(args);
	return (num);
}
