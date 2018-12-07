/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:29:42 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/21 20:36:13 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_c_w(const char *s, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			words++;
		}
		i++;
	}
	return (words);
}
