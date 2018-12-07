/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:24:47 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/20 21:13:07 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if (!(mem = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_bzero(mem, size + 1);
	return (mem);
}
