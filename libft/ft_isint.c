/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:54:44 by jdescler          #+#    #+#             */
/*   Updated: 2018/12/15 12:21:44 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			break;
		i++;
	}
	return (i == ft_strlen(s));
}
