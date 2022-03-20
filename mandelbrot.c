/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:44:55 by mvue              #+#    #+#             */
/*   Updated: 2022/03/20 02:10:58 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int cnt, int maxiter)
{
	int	r;
	int	g;
	int	b;

	r = 255 - cnt * 255 / maxiter;
	g = 255 - cnt * 255 / maxiter;
	b = 255 - cnt * 255 / maxiter;
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    mandelbrot(int maxiter, t_point screen, t_data img)
{
    t_complex 	c;
    t_complex 	z;
    t_point   	p;
	int			cnt;
	float		temp;
	float		real_start;
	float		real_end;
	float		ima_start;
	float		ima_end;

	real_start = -2;
	real_end = 1;
	ima_start = -1;
	ima_end = 1;
	p.y = 1;
	while (p.y < screen.y - 1)
	{
		p.x = 1;
		while (p.x < screen.x - 1)
		{
			c.real = real_start + (p.x / screen.x) * (real_end - real_start);
			c.ima = ima_start + (p.y / screen.y) * (ima_end - ima_start);
			z.real = 0;
			z.ima = 0;
			cnt = 0;
			while ((z.real * z.real + z.ima * z.ima < 4) && (cnt < maxiter))
			{
				temp = z.real * z.real - z.ima * z.ima + c.real;
				z.ima = 2 * z.real * z.ima + c.ima;
				z.real = temp;
				cnt++;
			}
			pixel_put(&img, p.x, p.y, create_color(cnt, maxiter));
			p.x++;
		}
		p.y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point	screen;
	int		i;
	int		j;
	float	xside;
	float	yside;
	float	top;
	float	left;
	int		maxiter;

	i = 0;
	j = 0;
	screen.x = 960;
	screen.y = 540;
	xside = 0.25 / screen.x;
	yside = 0.45 / screen.y;
    left = -1.75;
    top = -0.25;
	maxiter = 50;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screen.x, screen.y, "Hello world!");
	img.img = mlx_new_image(mlx, screen.x, screen.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mandelbrot(maxiter, screen, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}