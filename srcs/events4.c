/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:17:59 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/14 19:18:50 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors_contrast(t_mlx *v, int keycode)
{
	if (keycode == 24)
	{
		rgb_contrast_increment(v);
		extra_shrinking(v, keycode);
	}
	if (keycode == 27)
	{
		rgb_contrast_decrement(v);
		extra_shrinking(v, keycode);
	}
	if (keycode == 257 && v->shift_flag_right == 258)
	{
		v->shift_flag_left = 257;
		if (v->shift != 0)
			v->shift -= 100;
		else
			v->shift = 0;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	colors_management(t_mlx *v, int keycode)
{
	if (keycode == 8)
	{
		v->change = 8;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 7)
	{
		v->change = 7;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 9)
	{
		v->change = 9;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 258)
	{
		v->shift_flag_right = 258;
		v->shift += 100;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	events_call(t_mlx *v, int keycode)
{
	reset_event(v, keycode);
	fractal_event1(v, keycode);
	fractal_event2(v, keycode);
	fractal_mouvement1(v, keycode);
	fractal_mouvement2(v, keycode);
	iterations_control(v, keycode);
	fractals_rgb1(v, keycode);
	fractals_rgb2(v, keycode);
	colors_contrast(v, keycode);
	colors_management(v, keycode);
}

int		key_press(int keycode, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (keycode == 53)
	{
		ft_destroy(v);
		exit(0);
	}
	if (v->w.fract_select == 2)
	{
		if (keycode == 37)
			v->freeze = 0;
		if (keycode == 32)
			v->freeze = 1;
	}
	events_call(v, keycode);
	return (0);
}

void	zoom_events(t_mlx *v, int button, int x, int y)
{
	if (button == 5)
	{
		v->w.mouse_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->w.mouse_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		v->w.x1 = v->w.mouse_r + ((v->w.x1 - v->w.mouse_r) * 1.3);
		v->w.x2 = v->w.mouse_r + ((v->w.x2 - v->w.mouse_r) * 1.3);
		v->w.y1 = v->w.mouse_i + ((v->w.y1 - v->w.mouse_i) * 1.3);
		v->w.y2 = v->w.mouse_i + ((v->w.y2 - v->w.mouse_i) * 1.3);
	}
	if (button == 4)
	{
		v->w.mouse_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->w.mouse_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		v->w.x1 = v->w.mouse_r + ((v->w.x1 - v->w.mouse_r) * 0.7);
		v->w.x2 = v->w.mouse_r + ((v->w.x2 - v->w.mouse_r) * 0.7);
		v->w.y1 = v->w.mouse_i + ((v->w.y1 - v->w.mouse_i) * 0.7);
		v->w.y2 = v->w.mouse_i + ((v->w.y2 - v->w.mouse_i) * 0.7);
	}
}
