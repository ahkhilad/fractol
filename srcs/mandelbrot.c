/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:10:16 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/09 22:59:48 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrotset(t_mlx *r)
{
	r->w.row = 0;
	while (r->w.row < IMG_H)
	{
		r->w.col = 0;
		while (r->w.col < IMG_W)
		{
			var_init3(r);
			while (((r->w.x * r->w.x) + (r->w.y * r->w.y)) <= 4
					&& r->w.iter < r->w.max_iter)
			{
				r->w.x_new = (r->w.x * r->w.x) - (r->w.y * r->w.y) + r->w.com_r;
				r->w.y = (2 * r->w.x * r->w.y) + r->w.com_i;
				r->w.x = r->w.x_new;
				r->w.iter++;
			}
			if (r->w.iter < r->w.max_iter)
				r->rt[r->w.row * IMG_W + r->w.col] = 0xffffff;
			else
				r->rt[r->w.row * IMG_W + r->w.col] = 0xff3714;
			r->w.col++;
		}
		r->w.row++;
	}
	mlx_put_image_to_window(r->mlptr, r->wptr, r->iptr, 0, 0);
}

void	var_init3(t_mlx *var)
{
	var->w.com_r = (var->w.col - IMG_W / 2.0) * 4.0 / IMG_W;
	var->w.com_i = (var->w.row - IMG_H / 2.0) * 4.0 / IMG_W;
	var->w.x = 0;
	var->w.y = 0;
	var->w.iter = 0;
	var->w.max_iter = 300;
}
