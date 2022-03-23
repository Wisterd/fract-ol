/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:44:55 by mvue              #+#    #+#             */
/*   Updated: 2022/03/22 15:39:21 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	color_scale(int	cnt, int maxiter)
{
	float	scale;

	scale = (float)cnt / (float)maxiter;
	if (scale < 0.1)
		return (create_color(224, 30, 25));
	if (scale < 0.2)
		return (create_color(224,100,26));
	if (scale < 0.3)
		return (create_color(224,184,26));
	if (scale < 0.4)
		return (create_color(38,198,26));
	if (scale < 0.5)
		return (create_color(26,198,155));
	if (scale < 0.6)
		return (create_color(26,135,198));
	if (scale < 0.7)
		return (create_color(30,28,133));
	if (scale < 0.8)
		return (create_color(85,28,133));
	if (scale < 0.9)
		return (create_color(124,28,133));
	if (scale < 1)
		return (create_color(198,38,155));
	return (create_color(0,0,0));
}

/*
int	create_color(int cnt, int maxiter)
{
	t_rgb	color;

	//r = 255 - cnt * 255 / maxiter;
	color.r = 0;
	color.g = 255 - cnt * 255 / maxiter;
	color.b = 255 - cnt * 255 / maxiter;
	return (0 << 24 | color.r << 16 | color.g << 8 | color.b);
}
*/

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_complex	mandel_init(float epsi, t_point p, t_point screen)
{
	float				real_start;
	float				real_end;
	float				ima_start;
	float				ima_end;
	t_complex			c;

	real_start = -2;
	real_end = 1;
	ima_start = -1;
	ima_end = 1;
	c.real = real_start + (p.x / screen.x) * (real_end - real_start);
	c.ima = ima_start + (p.y / screen.y) * (ima_end - ima_start);
	c.real *= epsi;
	c.ima  *= epsi;
	c.real -= sqrt(0.755 * 0.755 - 0.1 * 0.1);
	c.ima += 0.1;
	return (c);
}

void    mandelbrot(int maxiter, t_point screen, t_data img, float epsi)
{
    t_complex 	c;
    t_complex 	z;
    t_point   	p;
	int			cnt;
	float		temp;

	p.y = 1;
	while (p.y < screen.y - 1)
	{
		p.x = 1;
		while (p.x < screen.x - 1)
		{
			c = mandel_init(epsi, p, screen);
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
			pixel_put(&img, p.x, p.y, color_scale(cnt, maxiter));
			p.x++;
		}
		p.y++;
	}
}

int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	t_point			screen;
	int				i;
	int				j;
	int				maxiter;

	i = 0;
	j = 0;
	screen.x = 960;
	screen.y = 540;
	maxiter = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screen.x, screen.y, "Fractol");
	img.img = mlx_new_image(mlx, screen.x, screen.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mandelbrot(maxiter, screen, img, 1);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	scroll_hook(init_zoom(maxiter, mlx, mlx_win, screen));
	mlx_loop(mlx);
}