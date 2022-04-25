/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:18 by mvue              #+#    #+#             */
/*   Updated: 2022/04/25 17:02:44 by mvue             ###   ########.fr       */
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
# define STEP_MV 0.2
# define RESO_X 1600
# define RESO_Y 1200
# define MAX_ITER 500
# define N1 49
# define N2 50
# define N3 51
# define N4 52
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

typedef struct s_mlx_parameters
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_mlx_params;

typedef struct s_complex_plane
{
	double		c_r;
	double		c_i;
	double		r_start;
	double		r_end;
	double		i_start;
	double		i_end;
}				t_cplane;

typedef struct s_zoom_parameters
{
	t_mlx_params	*mlx;
	double			*zoom_rate;
	int				id_set;
	t_cplane		*cplane;
	int				id_col;
}			t_zoom_params;

int				id_av(int ac, char **av);
double			ft_atof(char *str);
int				create_color(int r, int g, int b);
int				color_scale(int cnt, int maxiter, int id_col);
int				key_hooks(int key, t_zoom_params *zoom_params);
int				win_close(t_zoom_params *params);
void			julia(int maxiter, t_data *img, t_zoom_params zoom);
void			mandelbrot(int maxiter, t_data *img, t_zoom_params zoom);
void			ship(int maxiter, t_data *img, t_zoom_params zoom);
void			ft_print_instruct(void);
void			check_params(int ac, char **av);
int				check_complex(char *cr_str, char *ci_str);
t_complex		char_to_complex(char *cr_str, char *ci_str);
int				ft_strcmp(char *s1, char *s2);
void			ft_put_str(char *str);
void			pixel_put(t_data *data, int x, int y, int color);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
int				putkey(int keycode, t_mlx_params *params);
int				is_numb(char *str);
int				is_float(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(char *s1);
double			ft_abs(double d);
t_zoom_params	*init_zoom(t_mlx_params *mlx, double *zoom_rate, \
	int id_set, t_cplane *cplane);
int				zoom_hook(int button, int x, int y, t_zoom_params *param);

#endif
