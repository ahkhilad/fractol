/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:04:21 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/09/30 20:49:42 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 720
# define HEIGHT 600

# define IMG_W 600
# define IMG_H 600

# define MINI_IMG_W (WIDTH - IMG_W)
# define MINI_IMG_H (WIDTH - IMG_H)

# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct	s_var
{
	int			col;
	int			row;
	double		mouse_r;
	double		mouse_i;
	double		zoom_x;
	double		zoom_y;
	double		mini_zoom_x;
	double		mini_zoom_y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			iter;
	int			max_iter;
	double		mv_h;
	double		mv_v;
	int			fract_select;
	int			color;
}				t_var;

typedef struct	s_var1
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
}				t_var1;

typedef struct	s_mlx
{
	void		*mlptr;
	void		*wptr;
	void		*iptr;
	t_var		w;
	t_var1		l;
	int			*rt;
	int			bpp;
	int			size;
	int			end;
	int			freeze;
	pthread_t	core[8];
	int			color;
	int			r;
	int			g;
	int			b;
	int			re;
	int			gr;
	int			bl;
	int			change;
}				t_mlx;

void			mandelbrotset(t_mlx *v);
void			juliaset(t_mlx *v);
void			burning_ship_set(t_mlx *v);
void			tricorn_set(t_mlx *v);
void			initialize(t_mlx *v);
void			initialize1(t_mlx *v);
void			initialize2(t_mlx *v);
void			initialize3(t_mlx *v);
int				coloring(t_mlx *v, int nb);
void			usage(void);
int				mouse_move(int x, int y, void *p);
void			ft_clear(t_mlx *r);

void			mini_mandelbrotset(t_mlx *v);
void			mini_initialize(t_mlx *v);

#endif
