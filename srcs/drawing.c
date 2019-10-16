/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:21:14 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/13 16:34:27 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_draw(t_mlx *v, char *str)
{
	ft_mlx_init(v, str);
	v->w.fract_select = 1;
	initialize(v);
	mandelbrotset(v);
}

void	burning_ship_draw(t_mlx *v, char *str)
{
	ft_mlx_init(v, str);
	v->w.fract_select = 3;
	initialize2(v);
	burning_ship_set(v);
}

void	tricorn_draw(t_mlx *v, char *str)
{
	ft_mlx_init(v, str);
	v->w.fract_select = 4;
	initialize3(v);
	tricorn_set(v);
}

void	julia_draw(t_mlx *v, char *str)
{
	ft_mlx_init(v, str);
	v->w.fract_select = 2;
	initialize1(v);
	juliaset(v);
	mlx_hook(v->wptr, 6, 0, mouse_move, (void *)v);
}
