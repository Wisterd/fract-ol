/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:29 by mvue              #+#    #+#             */
/*   Updated: 2022/03/27 23:34:55 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_zoom_params main_init(void)
{
	t_zoom_params zoom_init;
	
	*(zoom_init.zoom_rate) = 1;
	zoom_init.mouse.x = 0;
	zoom_init.mouse.y = 0;
	return (zoom_init);
}

int	main(void)
{
	t_mlx_params	mlx;
	t_point			screen;
	int				maxiter;
	double			zoom_rate;

	screen.x = 960;
	screen.y = 540;
	maxiter = 100;
	zoom_rate = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, screen.x, screen.y, "Fractol");
	mlx.img.img = mlx_new_image(mlx.mlx, screen.x, screen.y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &(mlx.img.bits_per_pixel),
			&mlx.img.line_length, &mlx.img.endian);
	mandelbrot(maxiter, screen, mlx.img, main_init());
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	scroll_hook(init_zoom(maxiter, mlx, screen, &zoom_rate));
	mlx_key_hook(mlx.mlx_win, win_close, &mlx);
	//mlx_key_hook(mlx.mlx_win, putkey, &mlx);
	mlx_loop(mlx.mlx);
}