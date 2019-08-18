/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/09 22:59:38 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_clear(t_mlx *r)
{
	mlx_destroy_image(r->mlptr, r->iptr);
	mlx_clear_window(r->mlptr, r->wptr);
	r->iptr = mlx_new_image(r->mlptr, IMG_W, IMG_H);
	r->rt = (int *)mlx_get_data_addr(r->iptr, &r->bpp, &r->size, &r->end);
}

int		mouse_move(int x, int y, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	v->w.mv_r = (1.0 * x) / 3000;
	v->w.mv_i = (1.0 * y) / 3000;
	ft_clear(v);
	juliaset(v);
	return (0);
}

void	mlxshit(t_mlx *v, char *av)
{
	v->mlptr = mlx_init();
	v->wptr = mlx_new_window(v->mlptr, WIDTH, HEIGHT, av);
	v->iptr = mlx_new_image(v->mlptr, IMG_W, IMG_H);
	v->rt = (int *)mlx_get_data_addr(v->iptr, &v->bpp, &v->size, &v->end);
}

void	usage(void)
{
	ft_putstr("usage: binary file [fractal name].\n");
	ft_putstr("Available fractals :\n");
	ft_putstr("--> Mandelbrot\n");
	ft_putstr("--> Julia\n");
	ft_putstr("--> more ...\n");
}

void	fractal_set(t_mlx *v, char *av)
{
	char	*man;
	char	*jul;

	man = "Mandelbrot";
	jul = "Julia";
	var_init(v);
	if (ft_strcmp(av, man) == 0)
	{
		mlxshit(v, av);
		mandelbrotset(v);
	}
	else if (ft_strcmp(av, jul) == 0)
	{
		mlxshit(v, av);
		juliaset(v);
		mlx_hook(v->wptr, 6, 0, mouse_move, (void *)v);
	}
	else
	{
		usage();
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_mlx	v;

	if (argc != 2)
	{
		usage();
		exit(0);
	}
	if (argc == 2)
	{
		if (argv[1])
		{
			fractal_set(&v, argv[1]);
			mlx_loop(v.mlptr);
		}
	}
	return (0);
}
