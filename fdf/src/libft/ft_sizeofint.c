/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:30:46 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/13 17:32:25 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeofint(int n)
{
	int				size;
	unsigned int	nb;

	nb = ft_abs(n);
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
