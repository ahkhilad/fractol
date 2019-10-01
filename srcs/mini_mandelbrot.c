/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:06:08 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/09/29 00:03:54 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mini_root(t_mlx *v, t_var1 *x, int it)
{
	double  tmp;

	while ((x->z_r * x->z_r + x->z_i * x->z_i) < 4 && it < v->w.max_iter)
	{
		tmp = x->z_r;
		x->z_r = x->z_r * x->z_r - x->z_i * x->z_i + x->c_r;
		x->z_i = 2 * x->z_i * tmp + x->c_i;
		it += 1;
	}
	return (it);
}

void	mini_mandelbrotset(t_mlx *v)
{
	t_var1		x;
	int			it;
	int			t;

	v->w.col = 0;
	v->w.mini_zoom_x = MINI_IMG_W / (v->w.x2 - v->w.x1);
	v->w.mini_zoom_y = MINI_IMG_H / (v->w.y2 - v->w.y1);
	while (v->w.col < MINI_IMG_H)
	{
		v->w.row = 0;
		while (v->w.row < MINI_IMG_W)
		{
			x.c_r = v->w.row / v->w.mini_zoom_x + v->w.x1;
			x.c_i = v->w.col / v->w.mini_zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = mini_root(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[v->w.col * MINI_IMG_W + v->w.row] = coloring(v, t) * t;
			else
				v->rt[v->w.col * MINI_IMG_W + v->w.row] = 0;
			v->w.row +=1;
		}
		v->w.col += 1;
	}
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 600, 20);
}

void	mini_initialize(t_mlx *v)
{
	v->w.x1 = -3.6;
	v->w.x2 = 2.1;
	v->w.y1 = -1.0;
	v->w.y2 = 1.0;
	v->w.max_iter = 150;
}
