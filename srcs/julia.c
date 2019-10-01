/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:26:44 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/09/29 00:04:00 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		root1(t_mlx *v, t_var1 *x, int it)
{
	double	tmp;

	while ((x->z_r * x->z_r + x->z_i * x->z_i) < 4 && it < v->w.max_iter)
	{
		tmp = x->z_r;
		x->z_r = x->z_r * x->z_r - x->z_i * x->z_i + x->c_r;
		x->z_i = 2 * x->z_i * tmp + x->c_i;
		it += 1;
	}
	return (it);
}

void	*parti1(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti2(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti3(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti4(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti5(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti6(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti7(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	*parti8(void *param)
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
			x.c_r = v->l.c_r;
			x.c_i = v->l.c_i;
			x.z_r = j / v->w.zoom_x + v->w.x1;
			x.z_i = i / v->w.zoom_y + v->w.y1;
			it = 0;
			t = root1(v, &x, it);
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

void	juliaset(t_mlx *v)
{
	double	tmp;
	int		i;

	i = -1;
	v->w.zoom_x = IMG_W / (v->w.x2 - v->w.x1);
	v->w.zoom_y = IMG_H / (v->w.y2 - v->w.y1);
	pthread_create(&v->core[0], NULL, parti1, (void *)v);
	pthread_create(&v->core[1], NULL, parti2, (void *)v);
	pthread_create(&v->core[2], NULL, parti3, (void *)v);
	pthread_create(&v->core[3], NULL, parti4, (void *)v);
	pthread_create(&v->core[4], NULL, parti5, (void *)v);
	pthread_create(&v->core[5], NULL, parti6, (void *)v);
	pthread_create(&v->core[6], NULL, parti7, (void *)v);
	pthread_create(&v->core[7], NULL, parti8, (void *)v);
	while (++i < 8)
		pthread_join(v->core[i], NULL);
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 0, 0);
}

void	initialize1(t_mlx *v)
{
	v->w.x1 = -1.5;
	v->w.x2 = 1.5;
	v->w.y1 = -1.5;
	v->w.y2 = 1.5;
	v->l.c_i = 0.156;
	v->l.c_r = -0.8;
	v->w.max_iter = 200;
}
