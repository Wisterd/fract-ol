/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:44:55 by mvue              #+#    #+#             */
/*   Updated: 2022/03/30 18:17:54 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static t_complex	mandel_init(t_zoom_params zoom, t_point p, t_point screen)
{
	double				real_start;
	double				real_end;
	double				ima_start;
	double				ima_end;
	t_complex			c;

	real_start = -2;
	real_end = 1;
	ima_start = -1;
	ima_end = 1;
	c.real = real_start + p.x / screen.x * (real_end - real_start);
	c.ima = ima_start + p.y / screen.y * (ima_end - ima_start);
	c.real *= *(zoom.zoom_rate);
	c.ima  *= *(zoom.zoom_rate);
	//c.real += zoom.mouse.x / ((screen.x - 1) / (real_end - real_start)) + real_start;
	//c.ima += zoom.mouse.y / ((screen.y - 1) / (ima_end - ima_start)) + ima_start;
	return (c);
}

void    mandelbrot(int maxiter, t_point screen, t_data img, t_zoom_params zoom)
{
    t_complex 	c;
    t_complex 	z;
    t_point   	p;
	int			cnt;
	double		temp;

	p.y = 1;
	while (p.y < screen.y - 1)
	{
		p.x = 1;
		while (p.x < screen.x - 1)
		{
			c = mandel_init(zoom, p, screen);
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
