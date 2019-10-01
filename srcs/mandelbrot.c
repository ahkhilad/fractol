/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:25:16 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/01 15:33:50 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		root(t_mlx *v, t_var1 *x, int it)
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

void	*part1(void *param)
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
			t = root(v, &x, it);
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

void	*part2(void *param)
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
			t = root(v, &x, it);
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

void	*part3(void *param)
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
			t = root(v, &x, it);
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

void	*part4(void *param)
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
			t = root(v, &x, it);
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

void	*part5(void *param)
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
			t = root(v, &x, it);
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

void	*part6(void *param)
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
			t = root(v, &x, it);
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

void	*part7(void *param)
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
			t = root(v, &x, it);
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

void	*part8(void *param)
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
			t = root(v, &x, it);
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

void	mandelbrotset(t_mlx *v)
{
	double	tmp;
	int		i;

	i = -1;
	v->w.zoom_x = IMG_W / (v->w.x2 - v->w.x1);
	v->w.zoom_y = IMG_H / (v->w.y2 - v->w.y1);
	pthread_create(&v->core[0], NULL, part1, (void *)v);
	pthread_create(&v->core[1], NULL, part2, (void *)v);
	pthread_create(&v->core[2], NULL, part3, (void *)v);
	pthread_create(&v->core[3], NULL, part4, (void *)v);
	pthread_create(&v->core[4], NULL, part5, (void *)v);
	pthread_create(&v->core[5], NULL, part6, (void *)v);
	pthread_create(&v->core[6], NULL, part7, (void *)v);
	pthread_create(&v->core[7], NULL, part8, (void *)v);
	while (++i < 8)
		pthread_join(v->core[i], NULL);
	mlx_put_image_to_window(v->mlptr, v->wptr, v->iptr, 0, 0);
}

void	initialize(t_mlx *v)
{
	v->w.x1 = -2.1;
	v->w.x2 = 0.6;
	v->w.y1 = -1.2;
	v->w.y2 = 1.2;
	v->w.max_iter = 150;
}

int		coloring(t_mlx *v, int nb)
{
	int		red;
	int		green;
	int		blue;

	blue = nb * 150 / v->w.max_iter;
	green = 0;
	red = 0;
	if (v->color == 15 || v->color == 5 || v->color == 11)
	{
		blue = nb * v->b / v->w.max_iter;
		green = nb * v->g / v->w.max_iter;
		red = nb * v->r / v->w.max_iter;
		v->re = red;
		v->gr = green;
		v->bl = blue;
		if (v->change == 8)
		{
			blue = nb * v->b / v->w.max_iter + v->re;
			green = nb * v->g / v->w.max_iter + v->bl;
			red = nb * v->r / v->w.max_iter + v->gr;
		}
		if (v->change == 7)
		{
			blue = nb * v->b + v->gr;// / v->w.max_iter + green;
			green = nb * v->g + v->re;// / v->w.max_iter + red;
			red = nb * v->r + v->bl;// / v->w.max_iter + blue;
		}
	}
	return ((red << 16 | green << 8 | blue));
}
