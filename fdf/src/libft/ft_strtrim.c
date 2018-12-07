/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:06:00 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/21 15:21:39 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int start;
	int end;
	int len;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t') && s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\t' ||
				s[end] == '\n') && s[end] && end > start)
		end--;
	len = end - start;
	return (ft_strsub(s, start, len + 1));
}
