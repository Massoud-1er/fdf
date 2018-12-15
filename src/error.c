/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:03:47 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 21:22:11 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			error(int i)
{
	static int tmp = 0;

	if (i == 0)
		return (1);
	if (tmp == 0)
		tmp = i;
	if (tmp == i)
		return (0);
	put_exit();
	return (1);
}

void		put_exit(void)
{
	ft_putendl("oups, l'argument n'est pas valide");
	ft_putendl("assurez vous que la map est valide");
	ft_putendl("usage: ./fdf <map a tester>");
	exit(0);
}

void		put_exit_free(t_args *args)
{
	free_all(args);
	put_exit();
}
