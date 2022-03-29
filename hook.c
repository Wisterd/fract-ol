/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:40:15 by mvue              #+#    #+#             */
/*   Updated: 2022/03/27 00:51:39 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		win_close(int keycode, t_mlx_params *params)
{
	if (keycode == ESCP)
	{
		mlx_destroy_image(params->mlx, params->img.img);
		mlx_clear_window(params->mlx, params->mlx_win);
		mlx_destroy_window(params->mlx, params->mlx_win);
		free(params->mlx);
		exit(0);
	}
	return (0);
}
