/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 17:19:13 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int key, t_zoom_params *zoom_params)
{
	if (key == ESCP)
	{
		win_close(zoom_params);
		return (1);
	}
	return (0);
}

int		win_close(t_zoom_params *params)
{
	mlx_destroy_image(params->mlx->mlx, params->mlx->img.img);
	mlx_clear_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_window(params->mlx->mlx, params->mlx->mlx_win);
	mlx_destroy_display(params->mlx->mlx);
	free(params->mlx->mlx);
	free(params);
	exit(0);
	return (0);
}
