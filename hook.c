/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/04/05 16:41:38 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hooks(t_zoom_params *zoom_params)
{
	mlx_hook(zoom_params->mlx->mlx_win, 17, 1L << 3, win_close, zoom_params);
	mlx_hook(zoom_params->mlx->mlx_win, ESCP, 0, win_close, zoom_params);
}

int		win_close(t_zoom_params *params)
{
	mlx_destroy_image(params->mlx->mlx, params->mlx->img.img);
	mlx_clear_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_display(params->mlx->mlx);
	free(params->mlx);
	free(params);
	exit(0);
	return (0);
}
