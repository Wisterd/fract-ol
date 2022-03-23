/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:07 by mvue              #+#    #+#             */
/*   Updated: 2022/03/22 01:10:54 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_zoom_params	init_zoom(int maxiter, void *mlx, void *mlx_win, t_point screen)
{
	t_zoom_params	zoom_params;

	zoom_params.maxiter = maxiter;
	zoom_params.mlx = mlx;
	zoom_params.mlx_win = mlx_win;
	zoom_params.screen = screen;
	return(zoom_params);
}

int		zoom(int button, int x, int y, t_zoom_params *param)
{
	t_data	new_img;
	double	zoom_rate;

	new_img.img = mlx_new_image(param->mlx, param->screen.x, param->screen.y);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
		&new_img.line_length, &new_img.endian);
	(void) x;
	(void) y;
	if (button == SCROLLDOWN_KEY)
		zoom_rate = 1.2;
	if (button == SCROLLUP_KEY)
		zoom_rate = 1/1.2;
	mandelbrot(param->maxiter, param->screen, new_img, zoom_rate);
	mlx_put_image_to_window(param->mlx, param->mlx_win, new_img.img, 0, 0);
	return (1);
}

void	scroll_hook(t_zoom_params params)
{
	mlx_mouse_hook(params.mlx_win, zoom, &params);
	mlx_mouse_hook(params.mlx_win, zoom, &params);
}