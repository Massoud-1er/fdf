/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:05:41 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/11 12:22:04 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*pd;

	pd = dest;
	while (*src && len)
	{
		*pd++ = *src++;
		len--;
	}
	while (len--)
		*pd++ = '\0';
	return (dest);
}
