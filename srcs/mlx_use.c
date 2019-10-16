/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:46:59 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/13 16:51:13 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_destroy(t_mlx *v)
{
	mlx_destroy_image(v->mlptr, v->iptr);
	mlx_clear_window(v->mlptr, v->wptr);
	mlx_destroy_window(v->mlptr, v->wptr);
}

void	ft_reload_image(t_mlx *v)
{
	mlx_destroy_image(v->mlptr, v->iptr);
	mlx_clear_window(v->mlptr, v->wptr);
	v->iptr = mlx_new_image(v->mlptr, IMG_W, IMG_H);
	v->rt = (int *)mlx_get_data_addr(v->iptr, &v->bpp, &v->size, &v->end);
	options_menu(v);
	options_menu1(v);
	options_menu2(v);
}

void	ft_mlx_init(t_mlx *v, char *av)
{
	v->mlptr = mlx_init();
	v->wptr = mlx_new_window(v->mlptr, WIDTH, HEIGHT, av);
	v->iptr = mlx_new_image(v->mlptr, IMG_W, IMG_H);
	v->rt = (int *)mlx_get_data_addr(v->iptr, &v->bpp, &v->size, &v->end);
}
