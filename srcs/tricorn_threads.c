/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:27:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/12 16:50:49 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*partii4(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 4 * 3;
	while (x.i < IMG_H)
	{
		x.j = 0;
		while (x.j < IMG_W / 2)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = root3(v, &x, x.it);
			if (x.t < v->w.max_iter)
				v->rt[x.i * IMG_W + x.j] = coloring(v, x.t) * x.t;
			else
				v->rt[x.i * IMG_W + x.j] = 0;
			x.j += 1;
		}
		x.i += 1;
	}
	return (NULL);
}

void	*partii5(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = 0;
	while (x.i < IMG_H / 4)
	{
		x.j = IMG_W / 2;
		while (x.j < IMG_W)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = root3(v, &x, x.it);
			if (x.t < v->w.max_iter)
				v->rt[x.i * IMG_W + x.j] = coloring(v, x.t) * x.t;
			else
				v->rt[x.i * IMG_W + x.j] = 0;
			x.j += 1;
		}
		x.i += 1;
	}
	return (NULL);
}

void	*partii6(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 4;
	while (x.i < IMG_H / 2)
	{
		x.j = IMG_W / 2;
		while (x.j < IMG_W)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = root3(v, &x, x.it);
			if (x.t < v->w.max_iter)
				v->rt[x.i * IMG_W + x.j] = coloring(v, x.t) * x.t;
			else
				v->rt[x.i * IMG_W + x.j] = 0;
			x.j += 1;
		}
		x.i += 1;
	}
	return (NULL);
}

void	*partii7(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 2;
	while (x.i < (IMG_H / 4) * 3)
	{
		x.j = IMG_W / 2;
		while (x.j < IMG_W)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = root3(v, &x, x.it);
			if (x.t < v->w.max_iter)
				v->rt[x.i * IMG_W + x.j] = coloring(v, x.t) * x.t;
			else
				v->rt[x.i * IMG_W + x.j] = 0;
			x.j += 1;
		}
		x.i += 1;
	}
	return (NULL);
}

void	*partii8(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 4 * 3;
	while (x.i < IMG_H)
	{
		x.j = IMG_W / 2;
		while (x.j < IMG_W)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = root3(v, &x, x.it);
			if (x.t < v->w.max_iter)
				v->rt[x.i * IMG_W + x.j] = coloring(v, x.t) * x.t;
			else
				v->rt[x.i * IMG_W + x.j] = 0;
			x.j += 1;
		}
		x.i += 1;
	}
	return (NULL);
}
