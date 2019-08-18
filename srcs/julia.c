/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:35:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/09 23:45:59 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juliaset(t_mlx *v)
{
	v->w.row = 0;
	while (v->w.row < IMG_H)
	{
		v->w.col = 0;
		while (v->w.col < IMG_W)
		{
			var_init2(v);
			while ((v->w.x * v->w.x) + (v->w.y * v->w.y) < 4
					&& v->w.iter < v->w.max_iter)
			{
				v->w.x_new = (v->w.x * v->w.x) - (v->w.y * v->w.y) + v->w.mv_r;
				v->w.y = (2 * v->w.x * v->w.y) + v->w.mv_i;
				v->w.x = v->w.x_new;
				v->w.iter++;
			}
			if (v->w.iter < v->w.max_iter)
				v->rt[v->w.row * IMG_W + v->w.col] = 0;
			else
				v->rt[v->w.row * IMG_W + v->w.col] = 0xff3714;
			v->w.col++;
		}
		v->w.row++;
	}
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 0, 0);
}

void	var_init(t_mlx *var)
{
	var->w.row = 0;
	var->w.x = 0;
	var->w.y = 0;
	var->w.max_iter = 50;
	var->w.mv_r = -0.7;
	var->w.mv_i = 0.27015;
}

void	var_init2(t_mlx *var)
{
	var->w.x = (1.2 * (var->w.col - IMG_W / 2)) / ((0.5 * IMG_W) + var->w.x);
	var->w.y = (var->w.row - IMG_H / 2) / ((0.5 * IMG_H) + var->w.y);
	var->w.iter = 0;
}
