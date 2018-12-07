/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:31:08 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/07 21:28:20 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int print_line(t_args args, t_line line)
{
    int i, cumul;
    ft_putnbr(line.yinc);
    ft_putchar(' ');
    mlx_pixel_put(args.mlx_ptr, args.win_ptr, line.x, line.y, 16777215);
    if (line.dx > line.dy)
    {
        cumul = line.dx / 2;
        for (i = 1 ; i <= line.dx ; i++) 
        {
            line.x += line.xinc;
            cumul += line.dy;
            if (cumul >= line.dx)
            {
                cumul -= line.dx;
                line.y += line.yinc;
            }
            mlx_pixel_put(args.mlx_ptr, args.win_ptr, line.x, line.y, 16777215);
        } 
    }
    else
    {
      cumul = line.dy / 2;
      for ( i = 1 ; i <= line.dy ; i++ )
      {
        line.y += line.yinc;
        cumul += line.dx;
        if (cumul >= line.dy)
        {
          cumul -= line.dy;
          line.x += line.xinc;
        }
        mlx_pixel_put(args.mlx_ptr, args.win_ptr, line.x, line.y, 16777215);
        }
    }
    return (1);
}