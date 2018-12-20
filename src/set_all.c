/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:08:02 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 18:24:27 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_scale(t_point *trans, t_args args)
{
	int multi;

	multi = 300 / args.nb_lines > MIN_MULTI ? 300 / args.nb_lines : MIN_MULTI;
	multi = multi < MAX_MULTI ? multi : MAX_MULTI;
	if (multi + args.modif.zoom > 0)
	{
		trans->x -= args.x_pos;
		trans->x *= multi + args.modif.zoom;
		trans->y *= multi + args.modif.zoom;
		trans->x += args.x_pos;
	}
}

void	to_depth(t_point *trans, t_args args)
{
	trans->z *= args.modif.mod_z;
}

void	reverse_bis(t_point *trans, t_args args)
{
	trans->x -= args.x_pos;
	trans->x *= args.modif.mirror;
	trans->y *= args.modif.mirror;
	trans->x += args.x_pos;
}

void	set_all(t_point *i, t_point *f, t_args args)
{
	to_scale(i, args);
	to_scale(f, args);
	reverse_bis(f, args);
	reverse_bis(i, args);
	to_depth(i, args);
	to_depth(f, args);
}
