/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:34:40 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/07 21:28:21 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/get_next_line.h"



typedef	struct	s_point
{
	int x;
	int y;
	int	z;
}				t_point;

typedef	struct	s_line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x;
	int y;
	int dx;
	int dy;
	int xinc;
	int yinc;
}				t_line;

typedef struct	s_args
{
	void *mlx_ptr;
	void *win_ptr;
	char *file;
	t_point *all_int;
}				t_args;

int count_int(char *file);
t_point *parse (t_args args);
int make_line(t_point *int_all, t_args args);
int print_line(t_args args, t_line line);

#endif
