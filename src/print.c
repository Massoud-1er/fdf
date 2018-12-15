/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:29:15 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 23:11:08 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	to_iso(t_point i, t_point f, t_line *line, t_args args)
{
	line->x1 = (i.x - i.y) * cos(0.523599) + args.modif.mod_x;
	line->y1 = -i.z + (i.x + i.y) * sin(0.523599) + args.modif.mod_y;
	line->x2 = (f.x - f.y) * cos(0.523599) + args.modif.mod_x;
	line->y2 = -f.z + (f.x + f.y) * sin(0.523599) + args.modif.mod_y;
	line->line_x = line->x1;
	line->line_y = line->y1;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
}

void	to_para(t_point i, t_point f, t_line *line, t_args args)
{
	line->x1 = i.x - i.z * 2 + args.modif.mod_x;
	line->y1 = i.y - i.z * 5 + args.modif.mod_y;
	line->x2 = f.x - f.z * 2 + args.modif.mod_x;
	line->y2 = f.y - f.z * 5 + args.modif.mod_y;
	line->line_x = i.x - i.z * 2 + args.modif.mod_x;
	line->line_y = i.y - i.z * 5 + args.modif.mod_y;
	line->dx = (f.x - f.z * 2) - (i.x - i.z * 2);
	line->dy = (f.y - f.z * 5) - (i.y - i.z * 5);
}

int		print_setting(t_point i, t_point f, t_line *line, t_args args)
{
	set_all(&i, &f, args);
	if (args.modif.switch_proj)
		to_iso(i, f, line, args);
	if (!args.modif.switch_proj)
		to_para(i, f, line, args);
	line->line_z = i.z > f.z ? i.z : f.z;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = ft_abs(line->dx);
	line->dy = ft_abs(line->dy);
	return (1);
}

int		make_line(t_point *all_int, t_args args, t_img *image)
{
	int		i;
	int		j;
	int		size;
	t_line	line;

	size = count_int(args.file, 0);
	i = -1;
	j = 0;
	while (++i < size)
	{
		if ((i + 1) < size && all_int[i + 1].y == all_int[i].y)
		{
			print_setting(all_int[i], all_int[i + 1], &line, args);
			print_line(args, line, image);
		}
		while ((i + j) < size && all_int[i + j].y == all_int[i].y)
			j++;
		if (all_int[i].x == all_int[i + j].x)
		{
			print_setting(all_int[i], all_int[i + j], &line, args);
			print_line(args, line, image);
		}
	}
	mlx_put_image_to_window(args.mlx_ptr, args.win_ptr, args.image->ptr, 0, 0);
	return (1);
}
