/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:06:50 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/19 22:43:45 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ptr;
	t_list *tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		ptr = new;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
	}
	else
		return (NULL);
	new->next = NULL;
	return (ptr);
}
