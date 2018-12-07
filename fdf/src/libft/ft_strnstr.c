/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:37:32 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/11 11:35:17 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t			i;
	char			*j;
	char			*k;

	if (!*needle)
		return ((char *)haystack);
	while (n-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = n;
			j = (char *)haystack + 1;
			k = (char *)needle + 1;
			while (i-- && *j && *k && *j == *k)
			{
				++j;
				++k;
			}
			if (!*k)
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
