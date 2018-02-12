/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:38:16 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 17:38:17 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*get_color(char *form, t_color *run)
{
	int count;

	count = 0;
	if (*form == '{')
	{
		form++;
		ft_strncmp(form, "red}", 4) == 0 ? run->re = 1 : count++;
		ft_strncmp(form, "green}", 6) == 0 ? run->gre = 1 : count++;
		ft_strncmp(form, "yellow}", 7) == 0 ? run->yel = 1 : count++;
		ft_strncmp(form, "blue}", 5) == 0 ? run->blu = 1 : count++;
		ft_strncmp(form, "magenta}", 8) == 0 ? run->mag = 1 : count++;
		ft_strncmp(form, "cyan}", 5) == 0 ? run->cya = 1 : count++;
		ft_strncmp(form, "white}", 6) == 0 ? run->whi = 1 : count++;
		ft_strncmp(form, "reset}", 6) == 0 ? run->rese = 1 : count++;
		if (count != 8)
		{
			while (*form != '}')
				form++;
		}
		(*form == '}') ? form++ : form--;
	}
	return (form);
}

char	*ft_wrong(char *form, t_lst *run)
{
	char	*comp;

	comp = ft_strdup("sSpdDiouUxXcC%b-+ #0*.123456789lLhjz{}");
	if (*form == '}')
	{
		run->wrong = ft_realloc(run->wrong, ft_strlen(run->wrong) + 1);
		run->wrong = ft_strncat(run->wrong, form, 1);
	}
	else if (ft_strchr(comp, *form) == 0)
	{
		run->wrong = ft_realloc(run->wrong, ft_strlen(run->wrong) + 1);
		run->wrong = ft_strncat(run->wrong, form, 1);
	}
	ft_strdel(&comp);
	return (form);
}
