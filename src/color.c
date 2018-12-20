/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:21:24 by jdescler          #+#    #+#             */
/*   Updated: 2018/12/15 17:23:05 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		earth_color(int z, int max_z)
{
	double coef;

	coef = z * 100 / max_z;
	if (z == 0 || z == -1)
		return (0x014AF0);
	if (coef < 2)
		return (0xc2b280);
	if (coef < 5.5)
		return (0x4d9e3a);
	if (coef < 11)
		return (0x013220);
	if (coef < 20)
		return (0xB97E36);
	if (coef < 30)
		return (0xe1a95f);
	if (coef < 55)
		return (0x654321);
	else
		return (0xF9F9F9);
}

size_t		pyra_color(int z, int max_z)
{
	double coef;

	coef = z * 100 / max_z;
	if (coef < 2)
		return (0x754600);
	if (coef < 5.5)
		return (0x825007);
	if (coef < 11)
		return (0x9D661C);
	if (coef < 20)
		return (0xAB7128);
	if (coef < 30)
		return (0xB97E36);
	if (coef < 40)
		return (0xC68C46);
	if (coef < 45)
		return (0xD49A58);
	if (coef < 55)
		return (0xE1A96B);
	if (coef < 60)
		return (0xEFB97F);
	if (coef < 70)
		return (0xFDCA96);
	else
		return (0x754600);
}

size_t		rainbow_color(int z, int max_z)
{
	double coef;

	if (z == 0)
		return (0x0EBF00);
	coef = z * 100 / max_z;
	if (coef < 2)
		return (0x0EBF00);
	if (coef < 5.5)
		return (0x9AC600);
	if (coef < 10)
		return (0xCAB000);
	if (coef < 15)
		return (0xCE6B00);
	if (coef < 20)
		return (0xD22400);
	if (coef < 25)
		return (0xD90072);
	if (coef < 30)
		return (0xDD00C2);
	if (coef < 40)
		return (0xAE00E1);
	if (coef < 50)
		return (0x6000DE5);
	else
		return (0x0EBF00);
}

size_t		color_full(size_t color)
{
	if (color == GREEN)
		return (GREEN);
	if (color == BLUE)
		return (BLUE);
	if (color == RED)
		return (RED);
	if (color == ORANGE)
		return (ORANGE);
	if (color == PURPLE)
		return (PURPLE);
	if (color == YELLOW)
		return (YELLOW);
	else
		return (0);
}

size_t		fcolor(int z, int diff_z, size_t color_ref)
{
	if (color_ref == 1)
		return (mars_color(z, diff_z));
	if (color_ref == 2)
		return (pyra_color(z, diff_z));
	if (color_ref == 3)
		return (rainbow_color(z, diff_z));
	if (color_ref == 4)
		return (earth_color(z, diff_z));
	else
		return (color_ref);
}
