/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/14 19:18:48 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("Usage: binary file [fractal name].\n");
	ft_putstr("Available fractals :\n--> Mandelbrot\n--> Julia\n");
	ft_putstr("--> Burning_ship\n--> Tricorn\n");
}

void	fractal_set(t_mlx *v, char *av)
{
	char	*man;
	char	*jul;
	char	*bur;
	char	*tri;

	man = "Mandelbrot";
	jul = "Julia";
	bur = "Burning_ship";
	tri = "Tricorn";
	if (ft_strcmp(av, man) == 0)
		mandelbrot_draw(v, av);
	else if (ft_strcmp(av, bur) == 0)
		burning_ship_draw(v, av);
	else if (ft_strcmp(av, tri) == 0)
		tricorn_draw(v, av);
	else if (ft_strcmp(av, jul) == 0)
		julia_draw(v, av);
	else
	{
		usage();
		exit(0);
	}
}

int		mouse_press(int button, int x, int y, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (button == 5)
	{
		v->zoom -= 1;
		if (v->w.max_iter > 150)
			v->w.max_iter -= 5;
		ft_reload_image(v);
		zoom_events(v, button, x, y);
		fractal_selection(v);
	}
	if (button == 4)
	{
		v->zoom += 1;
		if (v->w.max_iter < 2000)
			v->w.max_iter += 5;
		ft_reload_image(v);
		zoom_events(v, button, x, y);
		fractal_selection(v);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	v;

	if (argc != 2)
	{
		usage();
		exit(0);
	}
	v.freeze = 1;
	v.zoom = 0;
	v.shift = 0;
	if (argc == 2)
	{
		if (argv[1])
		{
			fractal_set(&v, argv[1]);
			mlx_hook(v.wptr, 2, 0, key_press, (void *)&v);
			mlx_hook(v.wptr, 4, 0, mouse_press, (void *)&v);
			mlx_hook(v.wptr, 17, 0, red_button, (void *)&v);
			options_menu(&v);
			options_menu1(&v);
			options_menu2(&v);
			mlx_loop(v.mlptr);
		}
	}
	return (0);
}
