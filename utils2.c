/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:09:30 by mvue              #+#    #+#             */
/*   Updated: 2022/04/11 21:24:24 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_numb(char *str)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	if (!str)
		return (0);
	while (str[i++])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.'))
			return (0);
		if (str[i] == '.')
			cnt++;
		if (cnt > 1)
			return (0);
	}
	return (1);
}

int	is_float(char *str)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	while (str[i++])
		if (*str == '.')
			f = 1;
	return(f == 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
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