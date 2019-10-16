/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:04:21 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/10/15 13:51:30 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 950
# define HEIGHT 600

# define IMG_W 600
# define IMG_H 600

# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>
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
	int			i;
	int			j;
	int			t;
	int			it;
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
	int			change;
	int			zoom;
	int			shift;
	int			shift_flag_left;
	int			shift_flag_right;
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
int				mouse_move(int x, int y, void *p);
void			ft_reload_image(t_mlx *v);
void			ft_destroy(t_mlx *v);
void			usage(void);
void			ft_mlx_init(t_mlx *v, char *av);
void			options_menu(t_mlx *v);
void			options_menu1(t_mlx *v);
void			options_menu2(t_mlx *v);

int				root(t_mlx *v, t_var1 *x, int it);
void			*part4(void *param);
void			*part5(void *param);
void			*part6(void *param);
void			*part7(void *param);
void			*part8(void *param);

int				root1(t_mlx *v, t_var1 *x, int it);
void			*parti4(void *param);
void			*parti5(void *param);
void			*parti6(void *param);
void			*parti7(void *param);
void			*parti8(void *param);

int				root2(t_mlx *v, t_var1 *x, int it);
void			*partie4(void *param);
void			*partie5(void *param);
void			*partie6(void *param);
void			*partie7(void *param);
void			*partie8(void *param);

int				root3(t_mlx *v, t_var1 *x, int it);
void			*partii4(void *param);
void			*partii5(void *param);
void			*partii6(void *param);
void			*partii7(void *param);
void			*partii8(void *param);

void			mandelbrot_draw(t_mlx *v, char *str);
void			burning_ship_draw(t_mlx *v, char *str);
void			tricorn_draw(t_mlx *v, char *str);
void			julia_draw(t_mlx *v, char *str);

/*
**				events1 file functions
*/

int				mouse_move(int x, int y, void *p);
int				red_button(void *p);
void			reset_initialization(t_mlx *v);
void			reset_event(t_mlx *v, int keycode);
void			fractal_selection(t_mlx *v);

/*
**				events2 file functions
*/

void			fractal_event1(t_mlx *v, int keycode);
void			fractal_event2(t_mlx *v, int keycode);
void			fractal_mouvement1(t_mlx *v, int keycode);
void			fractal_mouvement2(t_mlx *v, int keycode);
void			iterations_control(t_mlx *v, int keycode);

/*
**				events3 file functions
*/

void			fractals_rgb1(t_mlx *v, int keycode);
void			fractals_rgb2(t_mlx *v, int keycode);
void			rgb_contrast_increment(t_mlx *v);
void			rgb_contrast_decrement(t_mlx *v);
void			extra_shrinking(t_mlx *v, int keycode);

/*
**				events4 file functions
*/

void			colors_contrast(t_mlx *v, int keycode);
void			colors_management(t_mlx *v, int keycode);
void			events_call(t_mlx *v, int keycode);
int				key_press(int keycode, void *p);
void			zoom_events(t_mlx *v, int button, int x, int y);

#endif
