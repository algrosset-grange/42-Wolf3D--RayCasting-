/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:09:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/03 16:09:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** -> : x(colone - horizontale), ^ : y(ligne - verticale)
** plus y est grand, plus il est bas
** ____________
**	c1 :
**	0
**			1
**	ou
**	0 		1
**
** ____________
**	c2 :
**	1
**			0
**	ou
**	1 		0
**
** ____________
**	c3 :
**			1
**	0
**
** ____________
**	c4 :
**			0
**	1
*/

void	ft_draw_col_c1(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int		x;
	int		y;

	x = p1_x_y[0];
	while (x <= p2_x_y[0])
	{
		y = p1_x_y[1] + (((double)p2_x_y[1] - (double)p1_x_y[1]) *
			(((double)x - (double)p1_x_y[0]) /
			((double)p2_x_y[0] - (double)p1_x_y[0])));
		ft_img_put_pixel(map, x, y, color);
		x++;
	}
}

void	ft_draw_col_c2(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int	temp[2];

	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
	ft_draw_col_c1(map, p1_x_y, p2_x_y, color);
	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
}

void	ft_draw_col_c3(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int		x;
	int		y;

	x = p1_x_y[0];
	while (x <= p2_x_y[0])
	{
		y = p1_x_y[1] + (((double)p2_x_y[1] - (double)p1_x_y[1]) *
			(((double)x - (double)p1_x_y[0]) /
			((double)p2_x_y[0] - (double)p1_x_y[0])));
		ft_img_put_pixel(map, x, y, color);
		x++;
	}
}

void	ft_draw_col_c4(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int	temp[2];

	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
	ft_draw_col_c3(map, p1_x_y, p2_x_y, color);
	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
}
