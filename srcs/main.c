/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/09/30 20:49:27 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clear(t_mlx *v)
{
	mlx_destroy_image(v->mlptr, v->iptr);
	//mlx_clear_window(v->mlptr, v->wptr);
	v->iptr = mlx_new_image(v->mlptr, IMG_W, IMG_H);
	v->rt = (int *)mlx_get_data_addr(v->iptr, &v->bpp, &v->size, &v->end);
}

int		mouse_move(int x, int y, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (v->freeze == 1)
	{
		v->l.c_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->l.c_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		ft_clear(v);
		juliaset(v);
	}
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
	//mlxshit(v, av);
	if (ft_strcmp(av, man) == 0)
	{
		mlxshit(v, av);
		mini_initialize(v);
		mini_mandelbrotset(v);
		v->w.fract_select = 1;
		initialize(v);
		mandelbrotset(v);
	}
	else if (ft_strcmp(av, bur) == 0)
	{
		mlxshit(v, av);
		mini_initialize(v);
		mini_mandelbrotset(v);
		v->w.fract_select = 3;
		initialize2(v);
		burning_ship_set(v);
	}
	else if (ft_strcmp(av, tri) == 0)
	{
		mlxshit(v, av);
		mini_initialize(v);
		mini_mandelbrotset(v);
		v->w.fract_select = 4;
		initialize3(v);
		tricorn_set(v);
	}
	else if (ft_strcmp(av, jul) == 0)
	{
		mlxshit(v, av);
		mini_initialize(v);
		mini_mandelbrotset(v);
		v->w.fract_select = 2;
		initialize1(v);
		juliaset(v);
		mlx_hook(v->wptr, 6, 0, mouse_move, (void *)v);
	}
	else
	{
		usage();
		exit(0);
	}
}

int		red_button(void	*p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	exit(0);
}

int		key_press(int keycode, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (keycode == 53)
		exit(0);
	if (v->w.fract_select == 2)
	{
		if (keycode == 37)
			v->freeze = 0;
		if (keycode == 32)
			v->freeze = 1;
	}
	if (keycode == 2)
	{
		ft_clear(v);
		v->color = 0;
		v->change = 0;
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
	if (keycode == 46)
	{
		initialize(v);
		ft_clear(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 1;
		mandelbrotset(v);
	}
	if (keycode == 38)
	{
		ft_clear(v);
		v->color = 0;
		v->change = 0;
		v->w.fract_select = 2;
		v->freeze = 1;
		initialize1(v);
		juliaset(v);
		mlx_hook(v->wptr, 6, 0, mouse_move, (void *)v);
	}
	if (keycode == 1)
	{
		initialize2(v);
		ft_clear(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 3;
		burning_ship_set(v);
	}
	if (keycode == 17)
	{
		initialize3(v);
		ft_clear(v);
		v->color = 0;
		v->change = 0;
		v->freeze = 0;
		v->w.fract_select = 4;
		tricorn_set(v);
	}
	if (keycode == 123)
	{
		v->w.mv_h = (v->w.x2 - v->w.x1) * 0.02;
		v->w.x1 = v->w.x1 + v->w.mv_h;
		v->w.x2 = v->w.x2 + v->w.mv_h;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 124)
	{
		v->w.mv_h = (v->w.x2 - v->w.x1) * 0.02;
		v->w.x1 = v->w.x1 - v->w.mv_h;
		v->w.x2 = v->w.x2 - v->w.mv_h;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 125)
	{
		v->w.mv_v = (v->w.y2 - v->w.y1) * 0.02;
		v->w.y1 = v->w.y1 - v->w.mv_v;
		v->w.y2 = v->w.y2 - v->w.mv_v;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 126)
	{
		v->w.mv_v = (v->w.y2 - v->w.y1) * 0.02;
		v->w.y1 = v->w.y1 + v->w.mv_v;
		v->w.y2 = v->w.y2 + v->w.mv_v;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 69)
	{
		if (v->w.max_iter < 2000)
		{
			v->w.max_iter += 5;
			ft_clear(v);
			if (v->w.fract_select == 1)
				mandelbrotset(v);
			if (v->w.fract_select == 2)
				juliaset(v);
			if (v->w.fract_select == 3)
				burning_ship_set(v);
			if (v->w.fract_select == 4)
				tricorn_set(v);
		}
	}
	if (keycode == 78)
	{
		if (v->w.max_iter > 150)
		{
			v->w.max_iter -= 5;
			ft_clear(v);
			if (v->w.fract_select == 1)
				mandelbrotset(v);
			if (v->w.fract_select == 2)
				juliaset(v);
			if (v->w.fract_select == 3)
				burning_ship_set(v);
			if (v->w.fract_select == 4)
				tricorn_set(v);
		}
	}
	/*
	 **		events for colors changing
	 */
	if (keycode == 15)
	{
		v->color = 15;
		v->g = 0;
		v->b = 0;
		v->r = 5;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 5)
	{
		v->color = 5;
		v->r = 0;
		v->b = 0;
		v->g = 5;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 11)
	{
		v->color = 11;
		v->r = 0;
		v->g = 0;
		v->b = 5;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 24)
	{
		if (v->color == 15)
		{
			v->g = 0;
			v->b = 0;
			if (v->r < 255)
			{
				v->r += 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
		else if (v->color == 5)
		{
			v->r = 0;
			v->b = 0;
			if (v->g < 255)
			{
				v->g += 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
		else if (v->color == 11)
		{
			v->r = 0;
			v->g = 0;
			if (v->b < 255)
			{
				v->b += 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
	}
	if (keycode == 27)
	{
		if (v->color == 15)
		{
			v->g = 0;
			v->b = 0;
			if (v->r > 5)
			{
				v->r -= 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
		else if (v->color == 5)
		{
			v->r = 0;
			v->b = 0;
			if (v->g > 5)
			{
				v->g -= 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
		else if (v->color == 11)
		{
			v->r = 0;
			v->g = 0;
			if (v->b > 5)
			{
				v->b -= 5;
				ft_clear(v);
				if (v->w.fract_select == 1)
					mandelbrotset(v);
				if (v->w.fract_select == 2)
					juliaset(v);
				if (v->w.fract_select == 3)
					burning_ship_set(v);
				if (v->w.fract_select == 4)
					tricorn_set(v);
			}
		}
	}
	if (keycode == 8)
	{
		v->change = 8;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (keycode == 7)
	{
		v->change = 7;
		ft_clear(v);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, void *p)
{
	t_mlx	*v;

	v = (t_mlx *)p;
	if (button == 5)
	{
		if (v->w.max_iter > 150)
			v->w.max_iter -= 5;
		ft_clear(v);
		v->w.mouse_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->w.mouse_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		v->w.x1 = v->w.mouse_r + ((v->w.x1 - v->w.mouse_r) * 1.2);
		v->w.x2 = v->w.mouse_r + ((v->w.x2 - v->w.mouse_r) * 1.2);
		v->w.y1 = v->w.mouse_i + ((v->w.y1 - v->w.mouse_i) * 1.2);
		v->w.y2 = v->w.mouse_i + ((v->w.y2 - v->w.mouse_i) * 1.2);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
	}
	if (button == 4)
	{
		v->w.max_iter += 5;
		ft_clear(v);
		v->w.mouse_r = x / (IMG_W / (v->w.x2 - v->w.x1)) + v->w.x1;
		v->w.mouse_i = y / (IMG_H / (v->w.y2 - v->w.y1)) + v->w.y1;
		v->w.x1 = v->w.mouse_r + ((v->w.x1 - v->w.mouse_r) * 0.8);
		v->w.x2 = v->w.mouse_r + ((v->w.x2 - v->w.mouse_r) * 0.8);
		v->w.y1 = v->w.mouse_i + ((v->w.y1 - v->w.mouse_i) * 0.8);
		v->w.y2 = v->w.mouse_i + ((v->w.y2 - v->w.mouse_i) * 0.8);
		if (v->w.fract_select == 1)
			mandelbrotset(v);
		if (v->w.fract_select == 2)
			juliaset(v);
		if (v->w.fract_select == 3)
			burning_ship_set(v);
		if (v->w.fract_select == 4)
			tricorn_set(v);
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
	if (argc == 2)
	{
		if (argv[1])
		{
			fractal_set(&v, argv[1]);
			mlx_hook(v.wptr, 2, 0, key_press, (void *)&v);
			mlx_hook(v.wptr, 4, 0, mouse_press, (void *)&v);
			mlx_hook(v.wptr, 17, 0, red_button, (void *)&v);
			mlx_loop(v.mlptr);
		}
	}
	return (0);
}
