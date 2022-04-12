/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:18 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 17:17:12 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define ESCP 65307
# define LEFT 65361
# define TOP 65362
# define RIGHT 65363
# define BOT 65364
# define RESO_X 1600
# define RESO_Y 1200
# define MAX_ITER 200

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
	double			*zoom_rate;
	t_point			mouse;
	int				id_set;
	t_complex		c;
}			t_zoom_params;

// atof.c
double			ft_atof(char *str);
// color.c
int				create_color(int r, int g, int b);
int				color_scale(int	cnt, int maxiter);
// hooks.c
int				key_hooks(int key, t_zoom_params *zoom_params);
int				win_close(t_zoom_params *params);
// julia.c
void			julia(int maxiter, t_data *img, t_zoom_params zoom);
// mandelbrot.c
void			mandelbrot(int maxiter, t_data *img, t_zoom_params zoom);
// parsing.c
int				check_complex(char *cr_str, char *ci_str);
t_complex		char_to_complex(char *cr_str, char *ci_str);
// utils.c
int				ft_strcmp(char *s1, char *s2);
void			ft_put_str(char *str);
void			pixel_put(t_data *data, int x, int y, int color);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
int				putkey(int keycode, t_mlx_params *params);
// utils2.c
int				is_numb(char *str);
int				is_float(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(char *s1);
// zoom.c
t_zoom_params	*init_zoom(t_mlx_params *mlx, double *zoom_rate, int id_set, t_complex c);
int				zoom_hook(int button, int x, int y, t_zoom_params *param);

#endif
