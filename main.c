/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:29 by mvue              #+#    #+#             */
/*   Updated: 2022/03/30 00:11:18 by mvue             ###   ########.fr       */
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
	int				maxiter;
	double			zoom_rate;

	screen.x = 960;
	screen.y = 540;
	maxiter = 100;
	zoom_rate = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, screen.x, screen.y, "Fractol");
	printf("%f, %f\n", screen.x, screen.y);
	mlx.img.img = mlx_new_image(mlx.mlx, screen.x, screen.y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &(mlx.img.bits_per_pixel),
			&mlx.img.line_length, &mlx.img.endian);
	mandelbrot(maxiter, screen, mlx.img, main_init(&zoom_rate));
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	scroll_hook(init_zoom(maxiter, mlx, screen, &zoom_rate));
	mlx_key_hook(mlx.mlx_win, win_close, &mlx);
	//mlx_key_hook(mlx.mlx_win, putkey, &mlx);
	mlx_loop(mlx.mlx);
}