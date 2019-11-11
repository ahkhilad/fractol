/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_initialization.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:52:40 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/24 20:21:28 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize(t_mlx *v)
{
	v->w.x1 = -2.1;
	v->w.x2 = 0.6;
	v->w.y1 = -1.2;
	v->w.y2 = 1.2;
	v->w.max_iter = 150;
}

void	initialize1(t_mlx *v)
{
	v->w.x1 = -1.5;
	v->w.x2 = 1.5;
	v->w.y1 = -1.5;
	v->w.y2 = 1.5;
	v->l.c_i = 0.156;
	v->l.c_r = -0.8;
	v->w.max_iter = 150;
}

void	initialize2(t_mlx *v)
{
	v->w.x1 = -2;
	v->w.x2 = 2;
	v->w.y1 = -2;
	v->w.y2 = 2;
	v->w.max_iter = 150;
}

void	initialize3(t_mlx *v)
{
	v->w.x1 = -2;
	v->w.x2 = 2;
	v->w.y1 = -2;
	v->w.y2 = 2;
	v->w.max_iter = 150;
}

void	initialize4(t_mlx *v)
{
	v->w.x1 = -1.5;
	v->w.x2 = 1.5;
	v->w.y1 = -1.5;
	v->w.y2 = 1.5;
	v->w.max_iter = 150;
}
