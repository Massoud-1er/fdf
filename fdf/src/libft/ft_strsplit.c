/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:50:37 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/27 16:25:32 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(arr = ft_megamalloc((char *)s, c)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = i;
			while (s[i] != c && s[i])
				i++;
			len = i - len;
			if (!(arr[j++] = ft_strsub(s, (i - len), len)))
				return (NULL);
		}
	}
	arr[j] = 0;
	return (arr);
}
