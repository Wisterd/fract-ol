/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:18 by mvue              #+#    #+#             */
/*   Updated: 2022/03/30 22:19:11 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define ESCP 53
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "../mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex_num
{
	double		real;
	double		ima;
}			t_complex;

typedef struct s_screen_point
{
	double	x;
	double	y;
}			t_point;

typedef struct	s_mlx_parameters
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_mlx_params;

typedef struct s_zoom_parameters
{
	int				maxiter;
	t_mlx_params	*mlx;
	t_point			screen;
	double			*zoom_rate;
	t_point			mouse;
}			t_zoom_params;

void			scroll_hook(t_zoom_params *param);
int				zoom_hook(int button, int x, int y, t_zoom_params *param);
void			key_hooks(t_zoom_params *close_params);
t_zoom_params	*init_zoom(int maxiter, t_mlx_params *mlx, t_point screen, double *zoom_rate);
void			mandelbrot(int maxiter, t_point screen, t_data img, t_zoom_params zoom);
int				win_close(t_zoom_params *params);
int				putkey(int keycode, t_mlx_params *params);
int				color_scale(int	cnt, int maxiter);

#endif
