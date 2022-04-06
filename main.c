/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:29 by mvue              #+#    #+#             */
/*   Updated: 2022/04/06 18:07:23 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_zoom_params main_init(double *zoom_rate)
{
	t_zoom_params 	zoom_init;

	zoom_init.zoom_rate = zoom_rate;
	zoom_init.mouse.x = 0;
	zoom_init.mouse.y = 0;
	return (zoom_init);
}

int	main(void)
{
	t_mlx_params	mlx;
	t_point			screen;
	double			zoom_rate;
	t_zoom_params	*zoom_params;

	screen.x = 960;
	screen.y = 540;
	zoom_rate = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, screen.x, screen.y, "Fractol");
	mlx.img.img = mlx_new_image(mlx.mlx, screen.x, screen.y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &(mlx.img.bits_per_pixel),
			&mlx.img.line_length, &mlx.img.endian);
	mandelbrot(200, screen, &mlx.img, main_init(&zoom_rate));
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	zoom_params = init_zoom(200, &mlx, screen, &zoom_rate);
	mlx_key_hook(zoom_params->mlx->mlx_win, key_hooks, zoom_params);
	mlx_hook(zoom_params->mlx->mlx_win, 17, 1L << 3, win_close, zoom_params);
	mlx_mouse_hook(zoom_params->mlx->mlx_win, zoom_hook, zoom_params);
	mlx_loop(mlx.mlx);
}