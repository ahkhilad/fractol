/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:35:19 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/24 22:17:52 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		source(t_mlx *v, t_var1 *x, int it)
{
	double	tmp;

	while ((x->z_r * x->z_r + x->z_i * x->z_i) < 4 && it < v->w.max_iter)
	{
		tmp = x->z_r;
		x->z_r = x->z_r * x->z_r - x->z_i * x->z_i + x->c_r;
		x->z_i = -2 * x->z_i * tmp + x->c_i;
		it += 1;
	}
	return (it);
}

void	*segment1(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = 0;
	while (x.i < IMG_H / 4)
	{
		x.j = 0;
		while (x.j < IMG_W / 2)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = source(v, &x, x.it);
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

void	*segment2(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 4;
	while (x.i < (IMG_H / 4) * 2)
	{
		x.j = 0;
		while (x.j < IMG_W / 2)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = source(v, &x, x.it);
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

void	*segment3(void *param)
{
	t_mlx	*v;
	t_var1	x;

	v = (t_mlx*)param;
	x.i = IMG_H / 2;
	while (x.i < (IMG_H / 4) * 3)
	{
		x.j = 0;
		while (x.j < IMG_W / 2)
		{
			x.c_r = x.j / v->w.zoom_x + v->w.x1;
			x.c_i = x.i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			x.it = 0;
			x.t = source(v, &x, x.it);
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

void	tricorn_set(t_mlx *v)
{
	double	tmp;
	int		i;

	i = -1;
	v->w.zoom_x = IMG_W / (v->w.x2 - v->w.x1);
	v->w.zoom_y = IMG_H / (v->w.y2 - v->w.y1);
	pthread_create(&v->core[0], NULL, segment1, (void *)v);
	pthread_create(&v->core[1], NULL, segment2, (void *)v);
	pthread_create(&v->core[2], NULL, segment3, (void *)v);
	pthread_create(&v->core[3], NULL, segment4, (void *)v);
	pthread_create(&v->core[4], NULL, segment5, (void *)v);
	pthread_create(&v->core[5], NULL, segment6, (void *)v);
	pthread_create(&v->core[6], NULL, segment7, (void *)v);
	pthread_create(&v->core[7], NULL, segment8, (void *)v);
	while (++i < 8)
		pthread_join(v->core[i], NULL);
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 0, 0);
}
