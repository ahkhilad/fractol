/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:25:20 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/14 19:18:41 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	red_shifting(t_mlx *v, int nb, int *rgb)
{
	if (v->change == 8)
	{
		rgb[0] = 0.05 * nb * 255 * v->r;
		rgb[2] = (1 - 0.05) * nb * v->b;
		rgb[1] = v->g;
		if (v->shift_flag_right == 258)
		{
			rgb[0] = 0.05 * nb * 255 * v->r + v->shift;
			rgb[2] = (1 - 0.05) * nb * v->b + v->shift;
			rgb[1] = v->g + v->shift;
		}
		if (v->shift_flag_left == 257)
		{
			rgb[0] = 0.05 * nb * 255 * v->r + v->shift;
			rgb[2] = (1 - 0.05) * nb * v->b + v->shift;
			rgb[1] = v->g + v->shift;
		}
	}
}

void	green_shifting(t_mlx *v, int nb, int *rgb)
{
	if (v->change == 7)
	{
		rgb[0] = v->r;
		rgb[2] = (1 - 0.05) * nb * v->b;
		rgb[1] = 0.05 * nb * 255 * v->g;
		if (v->shift_flag_right == 258)
		{
			rgb[0] = v->r + v->shift;
			rgb[2] = (1 - 0.05) * nb * v->b + v->shift;
			rgb[1] = 0.05 * nb * 255 * v->g + v->shift;
		}
		if (v->shift_flag_left == 257)
		{
			rgb[0] = v->r + v->shift;
			rgb[2] = (1 - 0.05) * nb * v->b + v->shift;
			rgb[1] = 0.05 * nb * 255 * v->g + v->shift;
		}
	}
}

void	blue_shifting(t_mlx *v, int nb, int *rgb)
{
	if (v->change == 9)
	{
		rgb[1] = (1 - 0.05) * nb * v->g;
		rgb[0] = v->r;
		rgb[2] = 0.05 * nb * 255 * v->b;
		if (v->shift_flag_right == 258)
		{
			rgb[1] = (1 - 0.05) * nb * v->g + v->shift;
			rgb[0] = v->r + v->shift;
			rgb[2] = 0.05 * nb * 255 * v->b + v->shift;
		}
		if (v->shift_flag_left == 257)
		{
			rgb[1] = (1 - 0.05) * nb * v->g + v->shift;
			rgb[0] = v->r + v->shift;
			rgb[2] = 0.05 * nb * 255 * v->b + v->shift;
		}
	}
}

void	rgb_coloring(t_mlx *v, int nb, int *rgb)
{
	if (v->color == 15)
	{
		rgb[2] = 0;
		rgb[1] = 0;
		rgb[0] = nb * v->r / 150;
	}
	if (v->color == 5)
	{
		rgb[2] = 0;
		rgb[1] = nb * v->g / 150;
		rgb[0] = 0;
	}
	if (v->color == 11)
	{
		rgb[2] = nb * v->b / 150;
		rgb[1] = 0;
		rgb[0] = 0;
	}
}

/*
**rgb[0] : red
**rgb[1] : green
**rgb[2] : blue
*/

int		coloring(t_mlx *v, int nb)
{
	int		rgb[3];

	rgb[2] = nb * 100 / 150;
	rgb[1] = 0;
	rgb[0] = 0;
	rgb_coloring(v, nb, rgb);
	if (v->color == 15 || v->color == 5 || v->color == 11)
	{
		red_shifting(v, nb, rgb);
		green_shifting(v, nb, rgb);
		blue_shifting(v, nb, rgb);
	}
	return ((rgb[0] << 16 | rgb[1] << 8 | rgb[2]));
}
