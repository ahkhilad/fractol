/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:34:38 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/09/28 22:49:22 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		root2(t_mlx *v, t_var1 *x, int it)
{
	double	tmp;

	while ((x->z_r * x->z_r + x->z_i * x->z_i) < 4 && it < v->w.max_iter)
	{
		tmp = fabs(x->z_r);
		x->z_r = x->z_r * x->z_r - x->z_i * x->z_i + x->c_r;
		x->z_i = fabs(2 * x->z_i * tmp + x->c_i);
		it += 1;
	}
	return (it);
}

void	*partie1(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = 0;
	while (i < IMG_H / 4)
	{
		j = 0;
		while (j < IMG_W / 2)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie2(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 4;
	while (i < (IMG_H / 4) * 2)
	{
		j = 0;
		while (j < IMG_W / 2)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie3(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 2;
	while (i < (IMG_H / 4) * 3)
	{
		j = 0;
		while (j < IMG_W / 2)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie4(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 4 * 3;
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W / 2)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie5(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = 0;
	while (i < IMG_H / 4)
	{
		j = IMG_W / 2;
		while (j < IMG_W)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie6(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 4;
	while (i < IMG_H / 2)
	{
		j = IMG_W / 2;
		while (j < IMG_W)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie7(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 2;
	while (i < (IMG_H / 4) * 3)
	{
		j = IMG_W / 2;
		while (j < IMG_W)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	*partie8(void *param)
{
	t_mlx	*v;
	int		i;
	int		j;
	int		t;
	int		it;
	t_var1	x;

	v = (t_mlx*)param;
	i = IMG_H / 4 * 3;
	while (i < IMG_H)
	{
		j = IMG_W / 2;
		while (j < IMG_W)
		{
			x.c_r = j / v->w.zoom_x + v->w.x1;
			x.c_i = i / v->w.zoom_y + v->w.y1;
			x.z_r = 0;
			x.z_i = 0;
			it = 0;
			t = root2(v, &x, it);
			if (t < v->w.max_iter)
				v->rt[i * IMG_W + j] = coloring(v, t) * t;
			else
				v->rt[i * IMG_W + j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (NULL);
}

void	burning_ship_set(t_mlx *v)
{
	double	tmp;
	int		i;

	i = -1;
	v->w.zoom_x = IMG_W / (v->w.x2 - v->w.x1);
	v->w.zoom_y = IMG_H / (v->w.y2 - v->w.y1);
	pthread_create(&v->core[0], NULL, partie1, (void *)v);
	pthread_create(&v->core[1], NULL, partie2, (void *)v);
	pthread_create(&v->core[2], NULL, partie3, (void *)v);
	pthread_create(&v->core[3], NULL, partie4, (void *)v);
	pthread_create(&v->core[4], NULL, partie5, (void *)v);
	pthread_create(&v->core[5], NULL, partie6, (void *)v);
	pthread_create(&v->core[6], NULL, partie7, (void *)v);
	pthread_create(&v->core[7], NULL, partie8, (void *)v);
	while (++i < 8)
		pthread_join(v->core[i], NULL);
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 0, 0);
}

void	initialize2(t_mlx *v)
{
	v->w.x1 = -2;
	v->w.x2 = 2;
	v->w.y1 = -2;
	v->w.y2 = 2;
	v->w.max_iter = 150;
}
