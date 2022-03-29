/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:07 by mvue              #+#    #+#             */
/*   Updated: 2022/03/28 00:44:54 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_zoom_params	init_zoom(int maxiter, t_mlx_params mlx, t_point screen, double *zoom_rate)
{
	t_zoom_params	zoom_params;

	zoom_params.maxiter = maxiter;
	zoom_params.mlx = mlx;
	zoom_params.screen = screen;
	zoom_params.zoom_rate = zoom_rate;
	return(zoom_params);
}

static int		zoom_in(t_zoom_params *param)
{
	*(param->zoom_rate) *= 1/1.1;
	param->mlx.img.img = mlx_new_image(param->mlx.mlx, param->screen.x, param->screen.y);
	param->mlx.img.addr = mlx_get_data_addr(param->mlx.img.img, &(param->mlx.img.bits_per_pixel),
		&(param->mlx.img.line_length), &(param->mlx.img.endian));
	mandelbrot(param->maxiter, param->screen, param->mlx.img, *param);
	mlx_put_image_to_window(param->mlx.mlx, param->mlx.mlx_win, param->mlx.img.img, 0, 0);
	return (1);
}

static int		zoom_out(t_zoom_params *param)
{
	*(param->zoom_rate) *= 1.1;
	param->mlx.img.img = mlx_new_image(param->mlx.mlx, param->screen.x, param->screen.y);
	param->mlx.img.addr = mlx_get_data_addr(param->mlx.img.img, &(param->mlx.img.bits_per_pixel),
		&(param->mlx.img.line_length), &(param->mlx.img.endian));
	mandelbrot(param->maxiter, param->screen, param->mlx.img, *param);
	mlx_put_image_to_window(param->mlx.mlx, param->mlx.mlx_win, param->mlx.img.img, 0, 0);
	return(1);
}

int		zoom_hook(int button, int x, int y, t_zoom_params *param)
{
	t_point	mouse;

	mouse.x = x;
	printf("x : %d\n", x);
	printf("rescale x : %f\n", (float)x / 959 * 3);
	mouse.y = y;
	printf("y : %d\n", y);
	printf("rescale y : %f\n", (float)y / 539 * 2);
	param->mouse = mouse;
	if (button == SCROLLUP_KEY)
		return (zoom_in(param));
	if (button == SCROLLDOWN_KEY)
		return (zoom_out(param));
	return (0);
}

void	scroll_hook(t_zoom_params param)
{
	mlx_mouse_hook(param.mlx.mlx_win, zoom_hook, &param);
}