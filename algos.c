/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:44:55 by mvue              #+#    #+#             */
/*   Updated: 2022/04/21 23:41:46 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int maxiter, t_data *img, t_zoom_params zoom)
{
	t_complex	z;
	t_point		p;
	int			cnt;
	double		temp;

	p.y = -1;
	while (++p.y < RESO_Y - 1)
	{
		p.x = -1;
		while (++p.x < RESO_X - 1)
		{
			z.real = (zoom.cplane->r_start + p.x / RESO_X * (zoom.cplane->r_end
						- zoom.cplane->r_start)) * *zoom.zoom_rate;
			z.ima = (zoom.cplane->i_start + p.y / RESO_Y * (zoom.cplane->i_end
						- zoom.cplane->i_start)) * *zoom.zoom_rate;
			cnt = -1;
			while ((++cnt < maxiter) && (z.real * z.real + z.ima * z.ima < 4))
			{
				temp = z.real * z.real - z.ima * z.ima + *zoom.cplane->c_r;
				z.ima = 2 * z.real * z.ima + *zoom.cplane->c_i;
				z.real = temp;
			}
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter, zoom.id_col));
		}
	}
}

static t_complex	mandel_init(t_zoom_params zoom, t_point p)
{
	t_complex			c;

	c.real = zoom.cplane->r_start + p.x / RESO_X
		* (zoom.cplane->r_end - zoom.cplane->r_start);
	c.ima = zoom.cplane->i_start + p.y / RESO_Y
		* (zoom.cplane->i_end - zoom.cplane->i_start);
	c.real *= *zoom.zoom_rate;
	c.ima *= *zoom.zoom_rate;
	return (c);
}

void	mandelbrot(int maxiter, t_data *img, t_zoom_params zoom)
{
	t_complex	c;
	t_complex	z;
	t_point		p;
	int			cnt;
	double		temp;

	p.y = -1;
	while (++p.y < RESO_Y - 1)
	{
		p.x = -1;
		while (++p.x < RESO_X - 1)
		{
			c = mandel_init(zoom, p);
			z.real = 0;
			z.ima = 0;
			cnt = -1;
			while ((++cnt < maxiter) && (z.real * z.real + z.ima * z.ima < 4))
			{
				temp = z.real * z.real - z.ima * z.ima + c.real;
				z.ima = 2 * z.real * z.ima + c.ima;
				z.real = temp;
			}
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter, zoom.id_col));
		}
	}
}

void	ship(int maxiter, t_data *img, t_zoom_params zoom)
{
	t_complex	c;
	t_complex	z;
	t_point		p;
	int			cnt;
	double		temp;

	p.y = -1;
	while (++p.y < RESO_Y - 1)
	{
		p.x = -1;
		while (++p.x < RESO_X - 1)
		{
			c = mandel_init(zoom, p);
			z.real = 0;
			z.ima = 0;
			cnt = -1;
			while ((++cnt < maxiter) && (z.real * z.real + z.ima * z.ima < 4))
			{
				temp = ft_abs(z.real * z.real - z.ima * z.ima + c.real);
				z.ima = ft_abs(2 * z.real * z.ima + c.ima);
				z.real = temp;
			}
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter, zoom.id_col));
		}
	}
}
