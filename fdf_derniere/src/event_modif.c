/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:28:47 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 18:09:25 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			zoom(int key, t_args *args)
{
	if ((key == PLUS || key == CLICK_U) && args->modif.zoom < 60)
		args->modif.zoom += 5;
	if ((key == MINUS || key == CLICK_D) && args->modif.zoom > -20)
		args->modif.zoom -= 5;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}

int			depth(int key, t_args *args)
{
	if (key == CHEV_L && args->modif.mod_z < 20)
		args->modif.mod_z += 2;
	if (key == CHEV_R && args->modif.mod_z > -16)
		args->modif.mod_z += -2;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}

void		reverse(t_args *args)
{
	args->modif.mirror = args->modif.mirror == 1 ? -1 : 1;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
}

int			move(int key, t_args *args)
{
	if (key == AR_L)
		args->modif.mod_x -= 20;
	if (key == AR_R)
		args->modif.mod_x += 20;
	if (key == AR_U)
		args->modif.mod_y -= 20;
	if (key == AR_D)
		args->modif.mod_y += 20;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}
