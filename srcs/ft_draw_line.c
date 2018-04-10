/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:22:39 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:22:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** -> : x(colone - horizontale), ^ : y(ligne - verticale)
** plus y est grand, plus il est bas
** les ligne par ligne
** ____________
**	c1 :
**	0
**
**
**	  1
**	ou
**	0
**
**
**	1
**
** ____________
**	c2 :
**	1
**
**
**	  0
**	ou
**	1
**
**
**	0
**
** ____________
**	c3 :
**	  0
**
**
**	1
**
** ____________
**	c4 :
**	 1
**
**
**	0
*/

void	ft_draw_line_c1(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int		x;
	int		y;

	y = p1_x_y[1];
	while (y <= p2_x_y[1])
	{
		x = p1_x_y[0] + (((double)p2_x_y[0] - (double)p1_x_y[0]) *
			((double)y - (double)p1_x_y[1]) /
			((double)p2_x_y[1] - (double)p1_x_y[1]));
		ft_img_put_pixel(map, x, y, color);
		y++;
	}
}

void	ft_draw_line_c2(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int	temp[2];

	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
	ft_draw_line_c1(map, p1_x_y, p2_x_y, color);
	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
}

void	ft_draw_line_c3(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int		x;
	int		y;

	y = p1_x_y[1];
	while (y <= p2_x_y[1])
	{
		x = p1_x_y[0] + (((double)p2_x_y[0] - (double)p1_x_y[0]) *
			((double)y - (double)p1_x_y[1]) /
			((double)p2_x_y[1] - (double)p1_x_y[1]));
		ft_img_put_pixel(map, x, y, color);
		y++;
	}
}

void	ft_draw_line_c4(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int	temp[2];

	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
	ft_draw_line_c3(map, p1_x_y, p2_x_y, color);
	temp[0] = p1_x_y[0];
	temp[1] = p1_x_y[1];
	p1_x_y[0] = p2_x_y[0];
	p1_x_y[1] = p2_x_y[1];
	p2_x_y[0] = temp[0];
	p2_x_y[1] = temp[1];
}
