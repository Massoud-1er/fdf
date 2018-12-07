/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:51:57 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/30 17:28:39 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		free((void *)s1);
		return (str);
	}
	return (NULL);
}
