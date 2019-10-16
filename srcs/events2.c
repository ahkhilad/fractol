/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:48 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/13 17:09:25 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_event1(t_mlx *v, int keycode)
{
	if (keycode == 46)
	{
		initialize(v);
		v->zoom = 0;
		v->w.max_iter = 150;
		ft_reload_image(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 1;
		mandelbrotset(v);
	}
	if (keycode == 38)
	{
		v->zoom = 0;
		v->w.max_iter = 150;
		ft_reload_image(v);
		v->color = 0;
		v->change = 0;
		v->w.fract_select = 2;
		v->freeze = 1;
		initialize1(v);
		juliaset(v);
		mlx_hook(v->wptr, 6, 0, mouse_move, (void *)v);
	}
}

void	fractal_event2(t_mlx *v, int keycode)
{
	if (keycode == 1)
	{
		initialize2(v);
		v->zoom = 0;
		v->w.max_iter = 150;
		ft_reload_image(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 3;
		burning_ship_set(v);
	}
	if (keycode == 17)
	{
		initialize3(v);
		v->zoom = 0;
		v->w.max_iter = 150;
		ft_reload_image(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 4;
		tricorn_set(v);
	}
}

void	fractal_mouvement1(t_mlx *v, int keycode)
{
	if (keycode == 123)
	{
		v->w.mv_h = (v->w.x2 - v->w.x1) * 0.02;
		v->w.x1 = v->w.x1 + v->w.mv_h;
		v->w.x2 = v->w.x2 + v->w.mv_h;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 124)
	{
		v->w.mv_h = (v->w.x2 - v->w.x1) * 0.02;
		v->w.x1 = v->w.x1 - v->w.mv_h;
		v->w.x2 = v->w.x2 - v->w.mv_h;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 125)
	{
		v->w.mv_v = (v->w.y2 - v->w.y1) * 0.02;
		v->w.y1 = v->w.y1 - v->w.mv_v;
		v->w.y2 = v->w.y2 - v->w.mv_v;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	fractal_mouvement2(t_mlx *v, int keycode)
{
	if (keycode == 126)
	{
		v->w.mv_v = (v->w.y2 - v->w.y1) * 0.02;
		v->w.y1 = v->w.y1 + v->w.mv_v;
		v->w.y2 = v->w.y2 + v->w.mv_v;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	iterations_control(t_mlx *v, int keycode)
{
	if (keycode == 69)
	{
		if (v->w.max_iter < 2000)
		{
			v->w.max_iter += 5;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
	if (keycode == 78)
	{
		if (v->w.max_iter > 150)
		{
			v->w.max_iter -= 5;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
}
