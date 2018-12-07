/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:29:59 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/20 21:00:03 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *ptr;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	ptr = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (ptr);
}
