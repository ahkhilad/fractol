/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:10:03 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/13 17:17:41 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractals_rgb1(t_mlx *v, int keycode)
{
	if (keycode == 15)
	{
		v->color = 15;
		v->g = 0;
		v->b = 0;
		v->r = 5;
		ft_reload_image(v);
		fractal_selection(v);
	}
	if (keycode == 5)
	{
		v->color = 5;
		v->r = 0;
		v->b = 0;
		v->g = 5;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	fractals_rgb2(t_mlx *v, int keycode)
{
	if (keycode == 11)
	{
		v->color = 11;
		v->r = 0;
		v->g = 0;
		v->b = 5;
		ft_reload_image(v);
		fractal_selection(v);
	}
}

void	rgb_contrast_increment(t_mlx *v)
{
	if (v->color == 15)
	{
		v->g = 0;
		v->b = 0;
		if (v->r < 255)
		{
			v->r += 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
	else if (v->color == 5)
	{
		v->r = 0;
		v->b = 0;
		if (v->g < 255)
		{
			v->g += 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
}

void	rgb_contrast_decrement(t_mlx *v)
{
	if (v->color == 15)
	{
		v->g = 0;
		v->b = 0;
		if (v->r > 5)
		{
			v->r -= 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
	else if (v->color == 5)
	{
		v->r = 0;
		v->b = 0;
		if (v->g > 5)
		{
			v->g -= 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
}

void	extra_shrinking(t_mlx *v, int keycode)
{
	if (keycode == 24 && v->color == 11)
	{
		v->r = 0;
		v->g = 0;
		if (v->b < 255)
		{
			v->b += 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
	if (keycode == 27 && v->color == 11)
	{
		v->r = 0;
		v->g = 0;
		if (v->b > 5)
		{
			v->b -= 1;
			ft_reload_image(v);
			fractal_selection(v);
		}
	}
}
