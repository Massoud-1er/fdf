/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:00:17 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/07 21:01:19 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	(void)ac;
	t_args args;

	args.file = av[1];
	args.mlx_ptr = mlx_init();
	args.win_ptr = mlx_new_window(args.mlx_ptr, 500, 500, "mlx 42");
//	ft_d("q");
	make_line(parse(args), args);	//modif
	mlx_loop(args.mlx_ptr);
	return (0);
}