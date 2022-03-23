/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:18 by mvue              #+#    #+#             */
/*   Updated: 2022/03/22 12:10:14 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex_num
{
	float		real;
	float		ima;
}			t_complex;

typedef struct s_screen_point
{
	float	x;
	float	y;
}			t_point;

typedef struct	s_mlx_parameters
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx_params;

typedef struct s_zoom_parameters
{
	int			maxiter;
	void		*mlx;
	void		*mlx_win;
	t_point		screen;
}			t_zoom_params;

void			scroll_hook(t_zoom_params param);
int				zoom(int button, int x, int y, t_zoom_params *param);
t_zoom_params	init_zoom(int maxiter, void *mlx, void *mlx_win, t_point screen);
void   			mandelbrot(int maxiter, t_point screen, t_data img, float epsi);
#endif