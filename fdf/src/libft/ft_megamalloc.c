/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_megamalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:19:23 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/27 16:25:10 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_megamalloc(char *s, char c)
{
	char **arr;

	if (!(arr = (char**)malloc(sizeof(char*) * (ft_c_w(s, c) + 2))))
		return (NULL);
	return (arr);
}
