/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:44:55 by mvue              #+#    #+#             */
/*   Updated: 2022/04/14 23:44:42 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int maxiter, t_data *img, t_zoom_params zoom)
{
    t_complex 	z;
    t_point   	p;
	int			cnt;
	double		temp;

	p.y = 1;
	while (p.y < RESO_Y - 1)
	{
		p.x = 1;
		while (p.x < RESO_X - 1)
		{
			z.real = zoom.cplane->r_start + p.x / RESO_X * (zoom.cplane->r_end - zoom.cplane->r_start);
			z.ima = zoom.cplane->i_start + p.y / RESO_Y * (zoom.cplane->i_end - zoom.cplane->i_start);
			z.real *= *zoom.zoom_rate;
			z.ima *= *zoom.zoom_rate;
			cnt = 0;
			while ((z.real * z.real + z.ima * z.ima < 4) && (cnt < maxiter))
			{
				temp = z.real * z.real - z.ima * z.ima + *zoom.cplane->c_r;
				z.ima = 2 * z.real * z.ima + *zoom.cplane->c_i;
				z.real = temp;
				cnt++;
			}
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter));
			p.x++;
		}
		p.y++;
	}
}

static t_complex	mandel_init(t_zoom_params zoom, t_point p)
{
	t_complex			c;

	c.real = zoom.cplane->r_start + p.x / RESO_X * (zoom.cplane->r_end - zoom.cplane->r_start);
	c.ima = zoom.cplane->i_start + p.y / RESO_Y * (zoom.cplane->i_end - zoom.cplane->i_start);
	c.real *= *zoom.zoom_rate;
	c.ima  *= *zoom.zoom_rate;
	//c.real += zoom.mouse.x / ((screen.x - 1) / (real_end - real_start)) + real_start;
	//c.ima += zoom.mouse.y / ((screen.y - 1) / (ima_end - ima_start)) + ima_start;
	return (c);
}

void    mandelbrot(int maxiter, t_data *img, t_zoom_params zoom)
{
    t_complex 	c;
    t_complex 	z;
    t_point   	p;
	int			cnt;
	double		temp;

	p.y = 1;
	while (p.y < RESO_Y - 1)
	{
		p.x = 1;
		while (p.x < RESO_X - 1)
		{
			c = mandel_init(zoom, p);
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
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter));
			p.x++;
		}
		p.y++;
	}
}
