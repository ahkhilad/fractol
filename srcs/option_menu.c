/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:13:08 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/24 20:20:21 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	options_menu(t_mlx *v)
{
	int		co;

	co = 0xffffff;
	mlx_string_put(v->mlptr, v->wptr, 725, 10, 0x29b6f6, "----------");
	mlx_string_put(v->mlptr, v->wptr, 720, 20, 0x29b6f6, "| OPTIONS |");
	mlx_string_put(v->mlptr, v->wptr, 725, 32, 0x29b6f6, "----------");
	mlx_string_put(v->mlptr, v->wptr, 620, 70, 0x29b6f6, "[MOUSE]");
	mlx_string_put(v->mlptr, v->wptr, 760, 70, 0x29b6f6, "[NUM_PAD]");
	mlx_string_put(v->mlptr, v->wptr, 760, 95, co, "[ + ]");
	mlx_string_put(v->mlptr, v->wptr, 805, 95, co, "[ - ]");
	mlx_string_put(v->mlptr, v->wptr, 760, 125, co, "Increase/Decrease");
	mlx_string_put(v->mlptr, v->wptr, 790, 150, co, "Iterations");
	mlx_string_put(v->mlptr, v->wptr, 640, 95, co, "Zoom in");
	mlx_string_put(v->mlptr, v->wptr, 660, 115, co, "|^|");
	mlx_string_put(v->mlptr, v->wptr, 660, 130, co, "|v|");
	mlx_string_put(v->mlptr, v->wptr, 640, 150, co, "Zoom out");
	mlx_string_put(v->mlptr, v->wptr, 620, 175, 0x29b6f6, "[KEYBOARD]");
	mlx_string_put(v->mlptr, v->wptr, 620, 195, co, "[ L ]");
	mlx_string_put(v->mlptr, v->wptr, 665, 195, co, "[ U ]");
	mlx_string_put(v->mlptr, v->wptr, 720, 195, co, "Lock/Unlock (Julia)");
}

void	options_menu1(t_mlx *v)
{
	int		co;

	co = 0xffffff;
	mlx_string_put(v->mlptr, v->wptr, 620, 215, 0xf39c16, "[Fractals]");
	mlx_string_put(v->mlptr, v->wptr, 620, 235, co, "[ M ] Mandelbrot set");
	mlx_string_put(v->mlptr, v->wptr, 620, 255, co, "[ J ] Julia set");
	mlx_string_put(v->mlptr, v->wptr, 620, 275, co, "[ S ] Burning_ship set");
	mlx_string_put(v->mlptr, v->wptr, 620, 295, co, "[ T ] Tricon set");
	mlx_string_put(v->mlptr, v->wptr, 620, 315, co, "[ P ] Multibrot set");
	mlx_string_put(v->mlptr, v->wptr, 620, 340, 0xf39c16, "[RGB Colors]");
	mlx_string_put(v->mlptr, v->wptr, 620, 365, 0xff0000, "[ R ] Red");
	mlx_string_put(v->mlptr, v->wptr, 620, 385, 0x00ff00, "[ G ] Green");
	mlx_string_put(v->mlptr, v->wptr, 620, 405, 0x0000ff, "[ B ] Blue");
	mlx_string_put(v->mlptr, v->wptr, 620, 430, 0xf39c16, "[Colors Shifting]");
	mlx_string_put(v->mlptr, v->wptr, 700, 455, co, "[ X ]");
	mlx_string_put(v->mlptr, v->wptr, 745, 455, co, "[ C ]");
	mlx_string_put(v->mlptr, v->wptr, 790, 455, co, "[ V ]");
}

void	options_menu2(t_mlx *v)
{
	int		co;

	co = 0xffffff;
	mlx_string_put(v->mlptr, v->wptr, 620, 480, 0xf39c16, "[Colors Contrast]");
	mlx_string_put(v->mlptr, v->wptr, 720, 505, co, "[ + ]");
	mlx_string_put(v->mlptr, v->wptr, 765, 505, co, "[ - ]");
	mlx_string_put(v->mlptr, v->wptr, 620, 530, 0xf39c16, "[Reset]");
	mlx_string_put(v->mlptr, v->wptr, 690, 530, co, "[ D ]");
	mlx_string_put(v->mlptr, v->wptr, 750, 530, 0xf39c16, "| [Exit]");
	mlx_string_put(v->mlptr, v->wptr, 830, 530, co, "[ ESC ]");
	mlx_string_put(v->mlptr, v->wptr, 620, 560, co, "Zoom:x");
	mlx_string_put(v->mlptr, v->wptr, 680, 560, 0x37ff16, ft_itoa(v->zoom));
	mlx_string_put(v->mlptr, v->wptr, 720, 560, co, "|   Iterations :");
	mlx_string_put(v->mlptr, v->wptr, 880, 560, 0x37ff16, \
			ft_itoa(v->w.max_iter));
}
