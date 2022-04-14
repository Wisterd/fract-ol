/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:13:29 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 20:00:14 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_instruct(void)
{
	ft_put_str("The program draws fractals according to 3 sets.\n\
	To run it, execute either:\n\
	./fractol mandelbrot\n\
	./fractol julia c_real c_ima with c in [-2, 2]\n\
	./fractol ship\n");
	exit(EXIT_SUCCESS);
}

static t_zoom_params main_init(double *zoom_rate)
{
	t_zoom_params 	zoom_init;

	zoom_init.zoom_rate = zoom_rate;
	zoom_init.mouse.x = 0;
	zoom_init.mouse.y = 0;
	return (zoom_init);
}

int	id_av(int ac, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(av[1], "julia") == 0)
	{
		if (ac == 4)
			return (2);
		else
		{
			ft_print_instruct();
			return (0);	
		}
	}
	if (ft_strcmp(av[1], "ship") == 0)
		return (3);
	ft_print_instruct();
	return (0);
}

t_cplane	*launch_set(int	id_set, t_data *img_ptr, t_zoom_params zoom, char **av)
{
	t_cplane	*cplane;
	t_complex	c;

	cplane = malloc(sizeof(*cplane));
	cplane->r_start = -2;
	cplane->r_end= 2;
	cplane->i_start = -2;
	cplane->i_end = 2;
	zoom.cplane = cplane;
	if (id_set == 1)
		mandelbrot(MAX_ITER, img_ptr, zoom);
	if (id_set == 2)
	{
		if (check_complex(av[2], av[3]))
		{
			c = char_to_complex(av[2], av[3]);
			cplane->c_r = c.real;
			cplane->c_i = c.ima;
			julia(MAX_ITER, img_ptr, zoom);
		}
		else
			ft_print_instruct();
	}
	return (cplane);
}

int	main(int ac, char **av)
{
	t_mlx_params	mlx;
	double			zoom_rate;
	t_zoom_params	*zoom_params;
	int				id_set;
	t_cplane		*cplane;

	if (ac < 2)
		ft_print_instruct();
	id_set = id_av(ac, av);
	zoom_rate = 1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, RESO_X, RESO_Y, "Fractol");
	mlx.img.img = mlx_new_image(mlx.mlx, RESO_X, RESO_Y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &(mlx.img.bits_per_pixel),
			&mlx.img.line_length, &mlx.img.endian);
	cplane = launch_set(id_set, &mlx.img, main_init(&zoom_rate), av);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	zoom_params = init_zoom(&mlx, &zoom_rate, id_set, cplane);
	mlx_key_hook(zoom_params->mlx->mlx_win, key_hooks, zoom_params);
	mlx_hook(zoom_params->mlx->mlx_win, 17, 1L << 3, win_close, zoom_params);
	mlx_mouse_hook(zoom_params->mlx->mlx_win, zoom_hook, zoom_params);
	mlx_loop(mlx.mlx);
}