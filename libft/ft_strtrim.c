/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:04:57 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/10/31 19:04:58 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ("");
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[i])
		j--;
	if (j < i)
		return ("");
	if (!(res = ft_strnew(j - i + 1)))
		return (NULL);
	k = 0;
	while (i <= j)
		res[k++] = s[i++];
	return (res);
}
