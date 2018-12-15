/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:00:17 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 23:00:12 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_modif(t_args *args)
{
	args->modif.mod_x = 0;
	args->modif.mod_y = 0;
	args->modif.mod_z = 1;
	args->modif.zoom = 0;
	args->modif.switch_proj = 1;
	args->modif.color = 3;
	args->modif.mirror = 1;
	if (ft_strcmp(args->file, "test_maps/france.fdf") == 0)
		args->modif.color = 4;
	else if (ft_strcmp(args->file, "test_maps/pyramide.fdf") == 0)
		args->modif.color = 2;
	else if (ft_strcmp(args->file, "test_maps/mars.fdf") == 0)
		args->modif.color = 1;
	else
		args->modif.color = 3;
	return (1);
}

void		count_lines(char *file, int *x, int *y)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		nb_line++;
		free(line);
	}
	*y = nb_line;
	*x = *y * 2;
	if (close(fd) == -1)
		return ;
}

void		get_win_size(int *x, int *y)
{
	*x = *x * 40 < MAX_WIN_X ? *x * 40 : MAX_WIN_X;
	*y = *y * 60 < MAX_WIN_Y ? *y * 60 : MAX_WIN_Y;
	*x = *x > MIN_WIN_X ? *x : MIN_WIN_X;
	*y = *y > MIN_WIN_Y ? *y : MIN_WIN_Y;
}

int			main(int ac, char **av)
{
	t_args	args;
	t_point *all_ints;

	if (ac != 2)
		put_exit();
	args.file = av[1];
	init_modif(&args);
	all_ints = parse(&args);
	count_lines(av[1], &args.win_x, &args.win_y);
	args.nb_lines = args.win_y;
	get_win_size(&args.win_x, &args.win_y);
	args.mlx_ptr = mlx_init();
	if (!(args.win_ptr = mlx_new_window(args.mlx_ptr,
			args.win_x, args.win_y, "mlx 42")))
		put_exit_free(&args);
	if (!(args.image = create_image(args)))
		put_exit_free(&args);
	make_line(all_ints, args, args.image);
	mlx_key_hook(args.win_ptr, key_hooks, &args);
	mlx_mouse_hook(args.win_ptr, mouse_hook, &args);
	mlx_loop(args.mlx_ptr);
	return (0);
}
