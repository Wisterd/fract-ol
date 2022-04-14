/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:39:35 by mvue              #+#    #+#             */
/*   Updated: 2022/04/15 00:20:16 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_instruct(void)
{
	ft_put_str("The program draws fractals according to 3 sets.\n\
	To run it, execute either:\n\
	./fractol mandelbrot\n\
	./fractol julia c_real c_ima with c in [-2, 2]\n\
	./fractol ship\n");
	exit(EXIT_SUCCESS);
}

void	check_params(int ac, char **av)
{
	int	id_set;

	if (ac < 2)
		ft_print_instruct();
	id_set = id_av(ac, av);
	if (id_set == 2)
		if (!check_complex(av[2], av[3]))
			ft_print_instruct();
}

int	check_complex(char *cr_str, char *ci_str)
{
	t_complex	c;

	if (!is_numb(cr_str) || !is_numb(ci_str))
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
