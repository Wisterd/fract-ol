/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:26:13 by mvue              #+#    #+#             */
/*   Updated: 2022/04/12 13:26:57 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_float(char *ent_s, char *dec_s)
{
	double	ent_f;
	double	dec_f;

	ent_f = (double)ft_atoi(ent_s);
	dec_f = (double)ft_atoi(dec_s);
	dec_f /= pow(10.0, (double)ft_strlen(dec_s));
	return (ent_f + dec_f);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	char	*str_cpy;
	float	res;

	i = 0;
	sign = 1;
	str_cpy = ft_strdup(str);
	if (str_cpy[i] == '-')
		sign = -1;
	while (str_cpy[i])
	{
		if (str_cpy[i] == '.')
		{
			str_cpy[i] = '\0';
			break;
		}
		i++;
	}
	res = get_float(str_cpy, str_cpy + i + 1);
	free(str_cpy);
	return (res * sign);
}