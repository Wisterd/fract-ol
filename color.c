/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:14:35 by mvue              #+#    #+#             */
/*   Updated: 2022/04/21 23:42:15 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_scale(int cnt, int maxiter, int col_ind)
{
	static int	tab1[] = {0xeeeee4, 0x063970, 0x1e81b0, 0x76b5c5, 0xabdbe3};
	static int	tab2[] = {0xaf56e3, 0xcf2929, 0xe89210, 0xe8c810, 0xed79e2};
	static int	tab3[] = {0xCDA2AB, 0x048A81, 0x06D6A0, 0x54C6EB, 0x8A89C0};
	static int	tab4[] = {0xFF8600, 0x27187E, 0x758BFD, 0xAEB8FE, 0xF1F2F6};
	int			*tab;

	tab = NULL;
	if (col_ind == 1)
		tab = tab1;
	if (col_ind == 2)
		tab = tab2;
	if (col_ind == 3)
		tab = tab3;
	if (col_ind == 4)
		tab = tab4;
	if (cnt == maxiter)
		return (0x000);
	return (tab[cnt % 5]);
}
