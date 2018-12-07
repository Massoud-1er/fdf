/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:29:15 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/07 21:53:16 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int print_line(t_args args, t_line line)
{
		mlx_pixel_put(args.mlx_ptr, args.win_ptr, line.x, line.y, 16777215);
		i += 10;
		j += 10;
	}
	return (1);
}
*/
int	print_setting(t_point i, t_point f, t_line *line)
{   
//	ft_putnbr(line.yinc);
//	ft_putchar(' ');
	line->x1 = i.x;
	line->y1 = i.y;
	line->x2 = f.x;
	line->y2 = f.y;
	line->x = i.x;
	line->y = i.y;
	line->dx = f.x - i.x;
	line->xinc = ( line->dx > 0 ) ? 1 : -1;
    line->yinc = ( line->dy > 0 ) ? 1 : -1;
	line->dx = ft_abs(line->dx);
	line->dy = ft_abs(line->dy);
//	ft_putnbr(line.yinc);
//	ft_putchar(' ');
//	ft_putchar('\n');
    return (1);
}

int make_line(t_point *all_int, t_args args)
{												
	int i;
	int j;
    int size;
	t_line line;

    size = count_int(args.file);
	i = 0;
	while (i < size)
	{
		j = 0;
		if ((i + 1) < size && all_int[i + 1].x == all_int[i].x)
		{
			print_setting(all_int[i], all_int[i + 1], &line);
			print_line(args, line);
		}
			ft_putnbr(all_int[i].x);
		while ((i + j) < size && all_int[i + j].y == all_int[i].y)
			j++;
		if ((i + j) < size)
		{
			print_setting(all_int[i], all_int[i + j], &line);
			print_line(args, line);
        }
		i++;
	}
	return (1);
}

