/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:56:49 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 23:12:30 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			diff(t_args args)
{
	int max;
	int min;
	int i;
	int limit;

	max = 0;
	min = 0;
	i = 0;
	limit = count_int(args.file, 0);
	while (i < limit)
	{
		if (max < args.all_int[i].z)
			max = args.all_int[i].z;
		if (min > args.all_int[i].z)
			min = args.all_int[i].z;
		i++;
	}
	return (max - min);
}

int			count_int(char *file, int nb)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	if ((fd = open(file, O_RDONLY)) == -1)
		put_exit();
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		tab = ft_strsplit(line, ' ');
		while (tab[++i])
		{
			if (!ft_isint(tab[i]))
				put_exit();
			free(tab[i]);
		}
		multi_free(line, tab);
		error(i);
		nb += i;
	}
	if (close(fd) == -1)
		put_exit();
	return (nb);
}

int			assign(char *line, int nb, t_args args)
{
	int			i;
	static int	j = 0;
	char		**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		args.all_int[j].x = i;
		args.all_int[j].y = nb;
		args.all_int[j].z = ft_atoi(tab[i]);
		i++;
		j++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

void		map_position(t_args *args, int x, int y, char *file)
{
	int i;
	int total;
	int x_pos;
	int y_pos;

	x_pos = x * 60 < MAX_WIN_X ? x * 60 : MAX_WIN_X;
	y_pos = y * 90 < MAX_WIN_Y ? y * 90 : MAX_WIN_Y;
	if ((total = count_int(file, 0)) < 5)
		put_exit();
	i = 0;
	args->x_pos = x_pos / 3;
	while (i < total)
	{
		args->all_int[i].x += x_pos / 3;
		i++;
	}
}

t_point		*parse(t_args *args)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	if ((fd = open(args->file, O_RDONLY)) == -1)
		put_exit();
	args->all_int = malloc_tab(count_int(args->file, 0));
	while (get_next_line(fd, &line) == 1)
	{
		assign(line, nb_line, *args);
		nb_line++;
		free(line);
	}
	map_position(args, nb_line * 2, nb_line, args->file);
	args->diff = diff(*args);
	if (close(fd) == -1)
		put_exit_free(args);
	return (args->all_int);
}
