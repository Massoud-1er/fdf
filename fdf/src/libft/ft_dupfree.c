/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:38:42 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/01 18:00:47 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dupfree(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free((void *)src);
	return (dest);
}
