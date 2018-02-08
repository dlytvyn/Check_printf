/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:30:00 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/18 16:30:01 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int     ft_len(char *s)
{
    int i;
    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	*ft_realloc(void *array, size_t size)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (array)
	{
        ft_bzero(res, size + 1);
		ft_strcpy(res, array);
		free(array);
	}
	return (res);
}


ssize_t	ft_atoi_n(const char *str)
{
    size_t				i;
    int					add;
    intmax_t         	res;

    res = 0;
    add = 1;
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-')
        add = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while ((str[i] >= '0' && str[i] <= '9') && str[i])
    {
        res *= 10;
        res += str[i] - '0';
        if (res > 9223372036854775807 && add == 1)
            return (-1);
        else if (res > 9223372036854775807 && add == -1)
            return (0);
        else
            i++;
    }
    return ((res * add));
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
    elem->wrong = ft_strdup("");
	return (elem);
}

const char	*ft_format(const char *form, t_lst *run)
{
	int	thing;

		thing = 0;
		while (*form && *form != '%')
		{
			run->text = ft_realloc(run->text, ft_strlen(run->text) + 1);
			run->text = ft_strncat(run->text, form, 1);
			form++;
		}
		if (*form == '%')
			form++;
		while (*form && thing == 0 &&*form != '\n')
		{
			form = ft_get_flags(form, run->flags);
			form = ft_get_width(form, run->width);
			form = ft_get_precision(form, run->precision);
			form = ft_get_length(form, run->length);
			thing = ft_get_specifier(form, run->specifier);
			if (thing == 0)
            	form = ft_wrong(form, run);
			form++;
            if (run->wrong[0])
                break;
		}
       // if (*form)
       // {
        //    run->next = ft_newlst();
        //    run = run->next;
       // }
	return (form);
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


char		*num_di(va_list args, t_length *run, t_specifier *spec)
{
	char	*res;

    if (run->z == 1)
        res = ft_itoa_base_pt(va_arg(args, size_t), spec);
    else if (run->j == 1)
        res = ft_itoa_base_pt(va_arg(args, intmax_t), spec);
    else if (run->ll)
        res = ft_itoa_base_pt(va_arg(args, long long int), spec);
    else if (run->l == 1)
        res = ft_itoa_base_pt(va_arg(args, long int), spec);
	else if (run->h == 1)
		res = ft_itoa_base_pt((short int)va_arg(args, int), spec);
	else if (run->hh == 1)
		res = ft_itoa_base_pt((signed char)va_arg(args, int), spec);
	else if (run->L == 1)
		res = ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec);
	else
		res = ft_itoa_base_pt(va_arg(args, int), spec);
	return (res);
}

char		*num_rest(va_list args, t_length *run, t_specifier *spec)
{
	char	*res;

    if (run->z == 1)
        res = ft_itoa_base(va_arg(args, size_t), search_base(spec), spec);
    else if (run->j == 1)
        res = ft_itoa_base(va_arg(args, uintmax_t), search_base(spec), spec);
    else if (run->ll)
        res = ft_itoa_base(va_arg(args, unsigned long long int), search_base(spec), spec);
    else if (run->l == 1)
        res = ft_itoa_base((size_t)va_arg(args, unsigned long int), search_base(spec), spec);
	else if (run->h == 1)
		res = ft_itoa_base((unsigned short int)va_arg(args, int), search_base(spec), spec);
	else if (run->hh == 1)
		res = ft_itoa_base((unsigned char)va_arg(args, int), search_base(spec), spec);
	else if (run->L == 1)
		res = ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec);
	else
		res = ft_itoa_base(va_arg(args, unsigned int), search_base(spec), spec);
	return (res);
}

char		*num_DOU(va_list args, t_specifier *spec, t_flags *flag)
{
	char    *res;

	res = ft_strdup("\0");
	if (spec->D)
		res = ft_itoa_base_pt(va_arg(args, long int), spec);
	else if (spec->O && flag->cell)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
    else if (spec->O)
        res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	else if (spec->U)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	return (res);
}

int        C_min(wchar_t c, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = unic_c(c);
    h = run->width->number - length_c(c);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    res += i;
    return (res);
}

int        C_n_min(wchar_t c, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0; 
    h = run->width->number - length_c(c);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    res = unic_c(c);
    res += i;
    return (res);
}

int        S_min(wchar_t *s, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = 0;
    if (run->precision->dot_number >= 0)
        res = unic_sn(s, run->precision->dot_number);
    else
        res = unic_s(s);
    if (run->precision->dot_number >= 0)
        h = run->width->number - run->precision->dot_number;
    else
        h = run->width->number - length_s(s);
    while (i < h)
    {
        ft_putchar(' ');
        i++;
    }
    res += i;
    return (res);
}

int        S_n_min(wchar_t *s, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = 0;
    if (run->precision->dot_number >= 0 || run->precision->fl)
        h = run->width->number - ulen_lim(run->precision->dot_number, s);
    else if (MB_CUR_MAX > 1)
        h = run->width->number - length_s(s);
    else
        h = run->width->number - length_s_one(s);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    if (run->precision->dot_number >= 0)
        res = unic_sn(s, run->precision->dot_number);
    else if (!run->precision->fl)
        res = unic_s(s);
    res += i;
    return (res);
}

int         char_CS(va_list args, t_lst *run)
{
    wchar_t c;
    wchar_t *s;

    if ((run->specifier->c && run->length->l) || run->specifier->C)
    {
        c = (va_arg(args, wint_t));
        if (run->flags->minus)
            return (C_min(c, run));
        else
            return (C_n_min(c, run));
    }
    else if ((run->specifier->s == 1 && run->length->l) || run->specifier->S)
    {
		s = (va_arg(args, wchar_t*));
        if (s == NULL)
            s = L"(null)";
        if (run->flags->minus)
            return (S_min(s, run));
        else
            return (S_n_min(s, run));
    }
    return (1);
}

char		*ft_char_type(va_list args, t_specifier *spec, t_length *length)
{
	char    *res;
    char    *temp;
    
	res = NULL;
	if (spec->c && !length->l)
    {
        res = ft_strnew(1);
		res[0] = (va_arg(args, int));
    }
	else if (spec->s == 1 && !length->l)
    {
        temp = (va_arg(args, char*));
        if (temp == NULL)
            res = ft_strdup("(null)");
        else
            res = ft_strdup(temp);
    }
	return (res);
}

int		is_num(t_specifier *spec, t_length *len)
{
	if (spec->d == 1|| spec->i == 1)
		return (1);
	else if (spec->o ==1|| spec->u == 1 || spec->x == 1 || spec->X == 1)
		return (2);
	else if (spec->D == 1 || spec->O == 1 || spec->U == 1)
		return (3);
	else if ((spec->c == 1 || spec->s == 1) && !len->l)
		return (4);
    else if (spec->C == 1 || spec->S == 1)
        return (7);
    else if ((spec->c == 1 || spec->s == 1) && len->l)
        return (7);
	else if (spec->p == 1)
		return (5);
	else if (spec->proc == 1)
		return (6);
	else
		return (0);
}

char		*parse_flags(intmax_t num, t_lst *run, char *res)
{
	char	*space;

	space = NULL;
	if (run->flags->plus && num >= 0 && (run->specifier->d || run->specifier->i))
	{
		space = ft_strdup("+");
		return (space);
	}
	else if (run->flags->space && num >= 0 && is_num(run->specifier, run->length) == 1)
	{
		space = ft_strdup(" ");
		return (space);
	}
	else if (run->flags->cell)
	{
		space = (run->specifier->o && res[0] != '0') ? ft_strdup("0") : space;
        space = (run->specifier->O && res[0] != '0') ? ft_strdup("0") : space;
		space = (run->specifier->x == 1 && num != 0) ? ft_strdup("0x") : space;
		space = (run->specifier->X == 1 && num != 0) ? ft_strdup("0X") : space;
		return (space);
	}
    else if (run->specifier->p)
        space = ft_strdup("0x");
	if (num < 0 && (run->specifier->d || run->specifier->i || run->specifier->D))
		space = ft_strdup("-");
	return (space);
}

char		*parse_accuracy(t_lst *run, char *num)
{
	int		ac;
    int 	size;
    int 	number;
    char	*temp;

    temp = NULL;
    if (run->precision->dot_number >= 0 && is_num(run->specifier, run->length) != 4 && !run->specifier->proc)
    {
        if (run->precision->dot_number > 0)
        {
            ac = run->precision->dot_number;
            size = ft_strlen(num);
            ((run->specifier->o || run->specifier->O) && run->precision->dot_number >= 0 && run->flags->cell) ? size++ : 1;
            number = ft_atoi(num);
            size = (number >= 0) ? size : size - 1;
            if (ac - size > 0)
            {
                temp = ft_strnew(ac - size);
                temp = ft_memset(temp, '0', ac - size);
            }
        }
    }
    return (temp);
}

int         type(t_lst *run)
{
    t_specifier *spec;

    spec = run->specifier;

    if (is_num(spec, run->length) == 4 || is_num(spec, run->length) == 6)
        return (1);
    else if (is_num(spec, run->length) == 7 || is_num(spec, run->length) == 0)
        return (1);
    else
        return (0);
}


char		*parse_width(t_lst *run, char *num, char *accur, char *flag)
{
	int 	width;
	char 	*temp;
    int     len;

    temp = NULL;
    len = (num[0] == '\0' && run->specifier->c) ? 1 : ft_len(num);
	if (run->width->number >= 0)
	{
		width = run->width->number;
		width = width - (len + ft_len(accur) + ft_len(flag));
		if (width > 0)
		{
			temp = ft_strnew(width);
			temp = ft_memset(temp, (run->flags->zero && !run->flags->minus && (!run->precision->fl || type(run))) ? '0' : ' ', width);
		}
	}
	return (temp);
}

void        ft_clear(char *width, char *accur, char *flag)
{
    if (width)
        ft_strdel(&width);
    if (accur)
        ft_strdel(&accur);
    if (flag)
        ft_strdel(&flag);
}

int         ft_text(t_lst *run)
{
    t_specifier *spec;

    spec = run->specifier;
    if (spec->S || spec->s)
        return (1);
    else
        return (0);
}

char		*pr_char(t_lst *run, char *num)
{
    int		ac;
    int 	size;
    char	*temp;

    if (run->precision->dot_number >= 0)
    {
        if (run->precision->dot_number > 0)
        {
            ac = run->precision->dot_number;
            size = ft_len(num);
            if (ac < size)
            {
                temp = ft_strnew(ac);
                temp = ft_strncpy(temp, num, ac);
            }
            else
                temp = num;
        }
        else
            temp = num;
    }
    else
        temp = num;
    return (temp);
}

int         ft_puttext_min(char *fl_ac, char *width, char *num, t_lst *run)
{
    int len;

    len = 0;
    (fl_ac != NULL) ? write(1, fl_ac, ft_len(fl_ac)) : 1;
    if (num[0] != '\0')
    {
        len = ft_len(num);
        write(1, num, len);
    }
    else if (num[0] == '\0' && run->specifier->c)
    {
        ft_putchar('\0');
        len = 1;
    }
    (width != NULL) ? write(1, width, ft_len(width)) : 1;
	//write(1, run->wrong, ft_strlen(run->wrong));
    len += ft_len(fl_ac) + ft_len(width);
    ft_clear(fl_ac, width, NULL);
    return (len);
}

int         ft_puttext_zero(char *fl_wd, char *accur, char *num, t_lst *run)
{
    int len;

    len = 0;
    (fl_wd != NULL) ? write(1, fl_wd, ft_strlen(fl_wd)) : 1;
    (accur != NULL) ? write(1, accur, ft_strlen(accur)) : 1;
    if (num[0] != '\0')
    {
        len = ft_strlen(num);
        write(1, num, len);
    }
    else if (num[0] == '\0' && run->specifier->c)
    {
        ft_putchar('\0');
        len = 1;
    }
	//write(1, run->wrong, ft_strlen(run->wrong));
    len += ft_len(fl_wd) + ft_len(accur);
    ft_clear(fl_wd, accur, NULL);
    return (len);
}

int         ft_puttext_min_p(char *fl_ac, char *width, char *num, t_lst *run)
{
	int len;

	len = 0;
    (fl_ac != NULL) ? write(1, fl_ac, ft_strlen(fl_ac)) : 1;
	if (num[0] != '\0')
	{
        len = ft_len(num);
		write(1, num, len);
	}
	else if (num[0] == '\0' && run->specifier->c)
	{
		ft_putchar('\0');
		len = 1;
	}
    (width != NULL) ? write(1, width, ft_strlen(width)) : 1;
	//write(1, run->wrong, ft_strlen(run->wrong));
	len += ft_len(fl_ac) + ft_len(width);
    ft_clear(fl_ac, width, NULL);
	return (len);
}

int         ft_puttext(char *wd_fl, char *accur, char *num, t_lst *run)
{
    int len;

    len = 0;
    (wd_fl != NULL) ? write(1, wd_fl, ft_len(wd_fl)) : 1;
    (accur != NULL) ? write(1, accur, ft_len(accur)) : 1;
    if (num[0] != '\0')
    {
        len = ft_len(num);
        write(1, num, len);
    }
    else if (num[0] == '\0' && run->specifier->c)
    {
        ft_putchar('\0');
        len = 1;
    }
	//write(1, run->wrong, ft_strlen(run->wrong));
    len += ft_len(wd_fl) + ft_len(accur);
    ft_clear(wd_fl, accur, NULL);
    return (len);
}

int        if_minus(t_lst *run, char *num)
{
    char	*width;
    char    *accur;
    char    *flag;
    int     len;

    flag = parse_flags(ft_atoi_n(num), run, num);
    accur = parse_accuracy(run, num);
    if (ft_atoi_n(num) < 0)
        num = num + 1;
    width = parse_width(run, num, accur, flag);
    len = ft_puttext_min(ft_realloc_cat(flag, accur), width, num, run);
    //ft_clear(width, accur, flag);
    return (len);
}

int        if_not_minus(t_lst *run, char *num)
{
    char	*width;
    char    *accur;
    char    *flag;
    int     len;

    len = 0;
    accur = parse_accuracy(run, num);
    flag = parse_flags(ft_atoi_n(num), run, num);
    if ((is_num(run->specifier, run->length) == 1 || run->specifier->D) && ft_atoi_n(num) < 0)
        num = num + 1;
    width = parse_width(run, num, accur, flag);
    if (run->flags->zero)
    {
        if (!run->specifier->p)
            len = ft_puttext_zero(ft_realloc_cat(flag, width), accur, num, run);
        else
            len = ft_puttext_min_p(ft_realloc_cat(flag, accur), width, num, run);
    }
    else if (!run->specifier->p)
        len = ft_puttext(ft_realloc_cat(width, flag), accur, num, run);
    else
    {
        if (run->flags->minus || run->precision->dot_number > run->width->number)
            len = ft_puttext_min_p(ft_realloc_cat(flag, accur), width, num, run);
        else
            len = ft_puttext_min_p(ft_realloc_cat(width, flag), accur, num, run);
    }
    //ft_clear(width, accur, flag);
    return (len);
}

int         ft_numeric(t_lst *run)
{
    t_specifier     *spec;

    spec = run->specifier;
    if (spec->x || spec->X || spec->d || spec->D || spec->i || spec->u || spec->U || spec->o || spec->O)
        return (1);
    else
        return (0);
}

int		ft_align(t_lst *run, char *num)
{
    if (ft_text(run) && run->precision->fl)
        num = pr_char(run, num);
    if (run->specifier->s && run->precision->fl && run->precision->dot_number <= 0)
    {
        free(num);
        num = ft_strdup("");
    }
	if (ft_atoi(num) == 0 && run->precision->fl && ft_numeric(run))
	{
		free(num);
		num = ft_strdup("");
	}
	if (run->flags->minus)
        return (if_minus(run, num));
	else
        return (if_not_minus(run, num));
}

int     ft_uni_type(t_specifier *spec, t_length *len)
{
    if (spec->C || (spec->c && len->l))
        return (1);
    else if (spec->S || (spec->s && len->l))
        return (1);
    else
        return (0);
}

char    *ft_pointer(char *res, va_list args, t_lst *head)
{
    char *temp;

    temp = ft_itoa_base((size_t)va_arg(args, void*), 16, head->specifier);
    if (!head->precision->fl || temp[0] != '0')
        res = temp;
    else
        res = ft_strdup("");
    return (res);
}


int		ft_typing(va_list args, t_lst *head)
{
    char	*res;
    int		size;

    res = NULL;
    size  = 0;
    if (head->text[0])
        write(1, head->text, ft_strlen(head->text));
    if (is_num(head->specifier, head->length) == 1)
        res = num_di(args, head->length, head->specifier);
    else if (is_num(head->specifier, head->length) == 2)
        res = num_rest(args, head->length, head->specifier);
    else if (is_num(head->specifier, head->length) == 3)
        res = num_DOU(args, head->specifier, head->flags);
    else if (is_num(head->specifier, head->length) == 4)
        res = ft_char_type(args, head->specifier, head->length);
    else if (is_num(head->specifier, head->length) == 5)
        res = ft_pointer(res, args, head);
    else if (is_num(head->specifier, head->length) == 6)
        res = ft_strdup("%");
    else if (is_num(head->specifier, head->length) == 7)
        size += char_CS(args, head);
    else if (head->wrong[0])
        res = ft_strdup(head->wrong);
    else
        return (ft_strlen(head->text));
    if ((ft_uni_type(head->specifier, head->length) == 0 || MB_CUR_MAX <= 1) && res)
        size += ft_align(head, res);
    size += ft_len(head->text);
    (head->specifier->proc) ? free(res) : 1;
    (head->wrong[0]) ? free(res) : 1;
    return (size);
}

int		ft_printf(const char *format, ...)
{
    va_list			args;
    const char		*form;
    t_lst			*head;
    int				num;

    num = 0;
    head = NULL;
    va_start(args, format);
    form = format;
    while (*form)
    {
		head = ft_newlst();
        form = ft_format(form, head);
        num += ft_typing(args, head);
        free(head->text);
        free(head->wrong);
		free(head);
    }
    va_end(args);
    return (num);
}
