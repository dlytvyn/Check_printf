/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:14:54 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/11/04 16:14:55 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	temp = f(lst);
	res = temp;
	while (lst->next)
	{
		temp->next = f(lst->next);
		temp = temp->next;
		lst = lst->next;
	}
	return (res);
}
