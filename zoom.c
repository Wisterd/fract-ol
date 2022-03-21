/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:07 by mvue              #+#    #+#             */
/*   Updated: 2022/03/21 19:45:51 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom(int button, int x, int y, void *param)
{
	t_data	new_img;
	double	zoom_rate;
	
	new_img.img = mlx_new_image(mlx, 960, 540);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
		&new_img.line_length, &new_img.endian);
	(void) x;
	(void) y;
	if (button == SCROLLDOWN_KEY)
		zoom_rate = 0.1;
	if (button == SCROLLUP_KEY)
		zoom_rate = -0.1;
	mandelbrot();

	return (0);
}

void	scroll_hook(void *win_ptr)
{
	mlx_hook(win_ptr, SCROLLDOWN_KEY, 0L, zoom, &);
	mlx_hook(win_ptr, SCROLLUP_KEY, 0L, zoom, &);
}