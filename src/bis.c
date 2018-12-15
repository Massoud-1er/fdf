/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:22:20 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 22:17:48 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		mars_color(int z, int max_z)
{
	double coef;

	coef = z * 100 / max_z;
	if (coef < 2)
		return (0x8A0055);
	if (coef < 6)
		return (0x8F004D);
	if (coef < 10)
		return (0x950044);
	if (coef < 15)
		return (0x9A0039);
	if (coef < 20)
		return (0xA0002E);
	if (coef < 25)
		return (0xA60022);
	if (coef < 30)
		return (0xB10006);
	if (coef < 40)
		return (0xB60800);
	if (coef < 70)
		return (0xBC1800);
	else
		return (0x8A0055);
}

t_point		*malloc_tab(int nb)
{
	t_point *tab;

	if (!(tab = (t_point *)malloc(sizeof(t_point) * nb)))
		return (NULL);
	return (tab);
}

void		free_all(t_args *args)
{
	free(args->all_int);
	if (args->image->image)
		free(args->image->image);
	if (args->image)
		free(args->image);
}
