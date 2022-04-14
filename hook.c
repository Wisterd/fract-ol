/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 19:50:02 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int key, t_zoom_params *zoom)
{
	if (key == ESCP)
	{
		win_close(zoom);
		return (1);
	}
	/*
	if (key == TOP)
		if (zoom->id_set == 1)
			mandelbrot()
	*/
	return (0);
}

int		win_close(t_zoom_params *params)
{
	mlx_destroy_image(params->mlx->mlx, params->mlx->img.img);
	mlx_clear_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_display(params->mlx->mlx);
	free(params->mlx->mlx);
	free(params->cplane);
	free(params);
	exit(0);
	return (0);
}
