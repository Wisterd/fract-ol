/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:09:30 by mvue              #+#    #+#             */
/*   Updated: 2022/04/21 23:43:30 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_numb(char *str)
{
	int	i;
	int	cnt;
	int	len;

	i = 0;
	cnt = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < len -1)
	{
		if (!ft_isdigit(str[i]) && !(str[i] == '.'))
			return (0);
		if (str[i] == '.')
			cnt++;
		if (cnt > 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_float(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] == '.')
			f = 1;
		i++;
	}
	return (f == 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*cp;
	int		i;

	len = ft_strlen(s1);
	cp = (char *)malloc(len + 1);
	i = 0;
	if (!cp)
		return (NULL);
	else
	{
		while (i < len + 1)
		{
			cp[i] = s1[i];
			i++;
		}
	}
	return (cp);
}

double	ft_abs(double d)
{
	if (d < 0)
		d *= -1;
	return (d);
}
