/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:52:41 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:44:28 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		ft_text_m(char *fl_ac, char *width, char *num, t_lst *run)
{
	int	len;

	len = 0;
	(fl_ac != NULL) ? write(1, fl_ac, ft_len(fl_ac)) : 1;
	if (num[0] != '\0')
	{
		len = ft_len(num);
		write(1, num, len);
	}
	else if (num[0] == '\0' && run->sp->c)
	{
		ft_putchar('\0');
		len = 1;
	}
	(width != NULL) ? write(1, width, ft_len(width)) : 1;
	len += ft_len(fl_ac) + ft_len(width);
	ft_clear(fl_ac, width, NULL);
	return (len);
}

int		ft_pt_zero(char *fl_wd, char *accur, char *num, t_lst *run)
{
	int	len;

	len = 0;
	(fl_wd != NULL) ? write(1, fl_wd, ft_strlen(fl_wd)) : 1;
	(accur != NULL) ? write(1, accur, ft_strlen(accur)) : 1;
	if (num[0] != '\0')
	{
		len = ft_strlen(num);
		write(1, num, len);
	}
	else if (num[0] == '\0' && run->sp->c)
	{
		ft_putchar('\0');
		len = 1;
	}
	len += ft_len(fl_wd) + ft_len(accur);
	ft_clear(fl_wd, accur, NULL);
	return (len);
}

int		pt_min_p(char *fl_ac, char *width, char *num, t_lst *run)
{
	int	len;

	len = 0;
	(fl_ac != NULL) ? write(1, fl_ac, ft_strlen(fl_ac)) : 1;
	if (num[0] != '\0')
	{
		len = ft_len(num);
		write(1, num, len);
	}
	else if (num[0] == '\0' && run->sp->c)
	{
		ft_putchar('\0');
		len = 1;
	}
	(width != NULL) ? write(1, width, ft_strlen(width)) : 1;
	len += ft_len(fl_ac) + ft_len(width);
	ft_clear(fl_ac, width, NULL);
	return (len);
}

int		ft_puttext(char *wd_fl, char *accur, char *num, t_lst *run)
{
	int	len;

	len = 0;
	(wd_fl != NULL) ? write(1, wd_fl, ft_len(wd_fl)) : 1;
	(accur != NULL) ? write(1, accur, ft_len(accur)) : 1;
	if (num[0] != '\0')
	{
		len = ft_len(num);
		write(1, num, len);
	}
	else if (num[0] == '\0' && run->sp->c)
	{
		ft_putchar('\0');
		len = 1;
	}
	len += ft_len(wd_fl) + ft_len(accur);
	ft_clear(wd_fl, accur, NULL);
	return (len);
}

char	*pr_char(t_lst *run, char *num)
{
	int		ac;
	int		size;
	char	*temp;

	if (run->pr->dot_number >= 0)
	{
		if (run->pr->dot_number > 0)
		{
			ac = run->pr->dot_number;
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
