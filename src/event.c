/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:29:17 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/12/15 18:37:50 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			colors(int key, t_args *args)
{
	if (key == K_NP_1)
		args->modif.color = 1;
	if (key == K_NP_2)
		args->modif.color = 2;
	if (key == K_NP_3)
		args->modif.color = 3;
	if (key == K_NP_4)
		args->modif.color = GREEN;
	if (key == K_NP_5)
		args->modif.color = BLUE;
	if (key == K_NP_6)
		args->modif.color = ORANGE;
	if (key == K_NP_7)
		args->modif.color = YELLOW;
	if (key == K_NP_8)
		args->modif.color = PURPLE;
	if (key == K_NP_9)
		args->modif.color = 4;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_args *args)
{
	(void)x;
	(void)y;
	if (button == CLICK_U)
	{
		zoom(button, args);
		return (0);
	}
	if (button == CLICK_D)
	{
		zoom(button, args);
		return (0);
	}
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}

int			switch_proj(t_args *args)
{
	args->modif.switch_proj = args->modif.switch_proj == 1 ? 0 : 1;
	clear_img(args->image);
	make_line(args->all_int, *args, args->image);
	return (0);
}

int			key_hooks(int key, void *args)
{
	if (key == ESC)
	{
		free_all(args);
		exit(0);
	}
	if (key == AR_L || key == AR_R || key == AR_U || key == AR_D)
		move(key, args);
	if (key == MINUS || key == PLUS)
		zoom(key, args);
	if (key == K_NP_1 || key == K_NP_2 || key == K_NP_3 || key == K_NP_4 ||
			key == K_NP_5 || key == K_NP_6 || key == K_NP_7 || key == K_NP_8 ||
			key == K_NP_9)
		colors(key, args);
	if (key == SPACE)
		switch_proj(args);
	if (key == CHEV_L || key == CHEV_R)
		depth(key, args);
	if (key == TAB)
		reverse(args);
	return (0);
}
