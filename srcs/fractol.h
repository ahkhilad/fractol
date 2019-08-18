/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:04:21 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/09 22:59:52 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 600
# define HEIGHT 500

# define IMG_W 500
# define IMG_H 500

# include "mlx.h"
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_var
{
	int			row;
	int			col;
	double		com_r;
	double		com_i;
	double		x;
	double		y;
	double		x_new;
	double		mv_r;
	double		mv_i;
	int			iter;
	int			max_iter;
}				t_var;

typedef struct	s_events
{
	int		m_mv;
}				t_events;

typedef struct	s_mlx
{
	void		*mlptr;
	void		*wptr;
	void		*iptr;
	t_var		w;
	t_events	ev;
	int			*rt;
	int			bpp;
	int			size;
	int			end;
}				t_mlx;

void			mandelbrotset(t_mlx *r);
void			juliaset(t_mlx *v);
void			usage(void);
void			var_init(t_mlx *var);
void			var_init2(t_mlx *var);
int		mouse_move(int x, int y, void *p);
void			var_init3(t_mlx *var);
void			ft_clear(t_mlx *r);
void	mlxshit2(t_mlx *v);

#endif
