/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:39:35 by mvue              #+#    #+#             */
/*   Updated: 2022/04/11 21:07:54 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_complex(char *cr_str, char *ci_str)
{
	t_complex	c;

	if (!(is_numb(cr_str) && is_numb(ci_str)))
		return (0);
	if (is_float(cr_str))
		c.real = ft_atof(cr_str);
	else
		c.real = (double)ft_atoi(cr_str);
	if (is_float(ci_str))
		c.ima = ft_atof(ci_str);
	else
		c.ima = (double)ft_atoi(ci_str);
	if (c.real * c.real + c.ima * c.ima < 4)
		return (1);
	return (0);
}

t_complex	char_to_complex(char *cr_str, char *ci_str)
{
	t_complex	c;

	if (is_float(cr_str))
		c.real = ft_atof(cr_str);
	else
		c.real = (double)ft_atoi(cr_str);
	if (is_float(ci_str))
		c.ima = ft_atof(ci_str);
	else
		c.ima = (double)ft_atoi(ci_str);
	return (c);
}
