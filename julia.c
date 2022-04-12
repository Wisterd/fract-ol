/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:47:46 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 14:38:32 by mvue             ###   ########.fr       */
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
	while (p.y < 539)
	{
		p.x = 1;
		while (p.x < 959)
		{
			z.real = -2 + p.x / 960 * 4;
			z.ima = -2 + p.y / 540 * 4;
			z.real *= *zoom.zoom_rate;
			z.ima *= *zoom.zoom_rate;
			cnt = 0;
			while ((z.real * z.real + z.ima * z.ima < 4) && (cnt < maxiter))
			{
				temp = z.real * z.real - z.ima * z.ima + zoom.c.real;
				z.ima = 2 * z.real * z.ima + zoom.c.ima;
				z.real = temp;
				cnt++;
			}
			pixel_put(img, p.x, p.y, color_scale(cnt, maxiter));
			p.x++;
		}
		p.y++;
	}
}