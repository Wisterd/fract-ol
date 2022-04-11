/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:14:35 by mvue              #+#    #+#             */
/*   Updated: 2022/04/11 21:10:36 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	color_scale(int	cnt, int maxiter)
{
	double	scale;

	scale = (double)cnt / (double)maxiter;
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
int	color_scale(int cnt, int maxiter)
{
	int	r;
	int	g;
	int	b;

	r = 255 - cnt * 255 / maxiter;
	g = 255 - cnt * 255 / maxiter;
	b = 255 - cnt * 255 / maxiter;
	return (0 << 24 | r << 16 | g << 8 | b);
}
*/