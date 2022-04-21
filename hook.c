/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/04/21 23:43:15 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_arrows(int key, t_zoom_params *zoom)
{
	if (key == TOP)
	{
		zoom->cplane->i_start -= STEP_MV;
		zoom->cplane->i_end -= STEP_MV;
	}
	if (key == BOT)
	{
		zoom->cplane->i_start += STEP_MV;
		zoom->cplane->i_end += STEP_MV;
	}
	if (key == LEFT)
	{
		zoom->cplane->r_start -= STEP_MV;
		zoom->cplane->r_end -= STEP_MV;
	}
	if (key == RIGHT)
	{
		zoom->cplane->r_start += STEP_MV;
		zoom->cplane->r_end += STEP_MV;
	}
}

static void	ft_numbers(int key, t_zoom_params *zoom)
{
	if (key == N1)
		zoom->id_col = 1;
	if (key == N2)
		zoom->id_col = 2;
	if (key == N3)
		zoom->id_col = 3;
	if (key == N4)
		zoom->id_col = 4;
}

int	key_hooks(int key, t_zoom_params *zoom)
{
	if (key == ESCP)
	{
		win_close(zoom);
		return (1);
	}
	ft_arrows(key, zoom);
	ft_numbers(key, zoom);
	if (zoom->id_set == 1)
		mandelbrot(MAX_ITER, &zoom->mlx->img, *zoom);
	if (zoom->id_set == 2)
		julia(MAX_ITER, &zoom->mlx->img, *zoom);
	if (zoom->id_set == 3)
		ship(MAX_ITER, &zoom->mlx->img, *zoom);
	mlx_put_image_to_window(zoom->mlx->mlx, \
	zoom->mlx->mlx_win, zoom->mlx->img.img, 0, 0);
	return (0);
}

int	win_close(t_zoom_params *params)
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
