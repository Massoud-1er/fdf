/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:07:07 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/19 22:46:28 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			nb;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	nb = 0;
	if (dst > src)
	{
		while (n)
		{
			pd[n - 1] = ps[n - 1];
			n--;
		}
	}
	else
	{
		while (nb++ < n)
			*pd++ = *ps++;
	}
	return (dst);
}
