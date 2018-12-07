/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:13:06 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/28 16:52:43 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
			i++;
		if (i == n)
			i--;
		return (s1[i] == s2[i]);
	}
	return (0);
}
