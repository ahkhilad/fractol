/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:52:39 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/24 20:31:09 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (v->freeze == 1)
	{
		v->l.c_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->l.c_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		ft_reload_image(v);
		juliaset(v);
	}
	return (0);
}

int		red_button(void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	ft_destroy(v);
	exit(0);
}

void	reset_initialization(t_mlx *v)
{
	v->zoom = 0;
	v->w.max_iter = 150;
	ft_reload_image(v);
	v->color = 0;
	v->change = 0;
}

void	reset_event(t_mlx *v, int keycode)
{
	if (keycode == 2)
	{
		reset_initialization(v);
		if (v->w.fract_select == 1)
		{
			initialize(v);
			mandelbrotset(v);
		}
		if (v->w.fract_select == 2)
		{
			initialize1(v);
			juliaset(v);
		}
		if (v->w.fract_select == 3)
		{
			initialize2(v);
			burning_ship_set(v);
		}
		if (v->w.fract_select == 4)
		{
			initialize3(v);
			tricorn_set(v);
		}
	}
}

void	fractal_selection(t_mlx *v)
{
	if (v->w.fract_select == 1)
		mandelbrotset(v);
	if (v->w.fract_select == 2)
		juliaset(v);
	if (v->w.fract_select == 3)
		burning_ship_set(v);
	if (v->w.fract_select == 4)
		tricorn_set(v);
	if (v->w.fract_select == 5)
		multibrotset(v);
}
