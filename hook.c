/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/03/30 18:37:23 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hooks(t_close_params *close_params)
{
	mlx_hook(close_params->mlx->mlx_win, 17, 1L << 3, win_close, close_params);
	mlx_hook(close_params->mlx->mlx_win, ESCP, 0, win_close, close_params);
}

int		win_close(t_close_params *params)
{
	mlx_destroy_image(params->mlx->mlx, params->mlx->img.img);
	mlx_clear_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_window(params->mlx->mlx, params->mlx->mlx_win);
	free(params->mlx);
	free(params->zoom_params);
	free(params);
	exit(0);
	return (0);
}
