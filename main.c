/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:29 by mvue              #+#    #+#             */
/*   Updated: 2022/03/30 18:38:32 by mvue             ###   ########.fr       */
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

t_close_params	*close_init(t_zoom_params *zoom_params, t_mlx_params *mlx)
{
	t_close_params *close_params;

	close_params = malloc(sizeof(*close_params));
	close_params->zoom_params = zoom_params;
	close_params->mlx = mlx;
	return (close_params);
}

int	main(void)
{
	t_mlx_params	mlx;
	t_point			screen;
	int				maxiter;
	double			zoom_rate;
	t_zoom_params	*zoom_params;

	screen.x = 960;
	screen.y = 540;
	maxiter = 300;
	zoom_rate = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, screen.x, screen.y, "Fractol");
	mlx.img.img = mlx_new_image(mlx.mlx, screen.x, screen.y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &(mlx.img.bits_per_pixel),
			&mlx.img.line_length, &mlx.img.endian);
	mandelbrot(maxiter, screen, mlx.img, main_init(&zoom_rate));
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	zoom_params = init_zoom(maxiter, mlx, screen, &zoom_rate);
	scroll_hook(zoom_params);
	key_hooks(close_init(zoom_params, &mlx));
	//mlx_key_hook(mlx.mlx_win, putkey, &mlx);
	mlx_loop(mlx.mlx);
}