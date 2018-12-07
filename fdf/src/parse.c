/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:31:10 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/07 21:52:37 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *malloc_tab(int nb, t_args args)
{
	t_point *tab;
	if (!(tab = (t_point *)malloc(sizeof(t_point) * nb)))
		return (NULL);
	return (tab);
}

int count_int(char *file)
{
	int i;
	int nb;
	int fd;
	char *line;
	char **tab;

	nb = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
			i++;
		nb += i;
	}
	return (nb);
}
/*
int	print_test(t_point point, t_args args)
{
	mlx_pixel_put(args.mlx_ptr, args.win_ptr, point.x, point.y, 16777215);
	return (1);
}
*/
int assign(char *line, int nb, t_args args)
{
	int i;
	static int j = 0;
	char **tab;
	
	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		args.all_int[j].x = i * 20 + 20;
		args.all_int[j].y = nb * 15 + 20;
		args.all_int[j].z = ft_atoi(tab[i]);
	//	ft_putnbr(args.all_int[j].x);
	//	ft_putchar(' ');
	//	print_test(args.all_int[j], args);
		i++;
		j++;
	}
	return (1);
}

t_point *parse(t_args args)
{
	int fd;
	char *line;
	int nb_line;
	
	nb_line = 0;
	fd = open(args.file, O_RDONLY);
	args.all_int = malloc_tab(count_int(args.file), args);
	while (get_next_line(fd, &line) == 1)
	{
		assign(line, nb_line, args);
		nb_line++;
	}
	return (args.all_int);		//modif
}
