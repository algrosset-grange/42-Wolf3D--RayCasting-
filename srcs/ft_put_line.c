/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:23:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:23:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** -> : x(colone - horizontale), ^ : y(ligne - verticale)
** plus y est grand, plus il est bas
** les ligne par ligne
*/

static void	ft_find_draw_line(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	if (p2_x_y[1] > p1_x_y[1] && p2_x_y[0] >= p1_x_y[0])
		ft_draw_line_c1(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[1] < p1_x_y[1] && p2_x_y[0] <= p1_x_y[0])
		ft_draw_line_c2(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[1] > p1_x_y[1] && p2_x_y[0] < p1_x_y[0])
		ft_draw_line_c3(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[1] < p1_x_y[1] && p2_x_y[0] > p1_x_y[0])
		ft_draw_line_c4(map, p1_x_y, p2_x_y, color);
}

static void	ft_find_draw_col(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	if (p2_x_y[0] > p1_x_y[0] && p2_x_y[1] >= p1_x_y[1])
		ft_draw_col_c1(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[0] < p1_x_y[0] && p2_x_y[1] <= p1_x_y[1])
		ft_draw_col_c2(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[0] > p1_x_y[0] && p2_x_y[1] < p1_x_y[1])
		ft_draw_col_c3(map, p1_x_y, p2_x_y, color);
	if (p2_x_y[0] < p1_x_y[0] && p2_x_y[1] > p1_x_y[1])
		ft_draw_col_c4(map, p1_x_y, p2_x_y, color);
}

void		ft_put_line(t_map *map, int *p1_x_y, int *p2_x_y, int color)
{
	int		abs_x;
	int		abs_y;

	abs_x = abs(p1_x_y[0] - p2_x_y[0]);
	abs_y = abs(p2_x_y[1] - p1_x_y[1]);
	if (abs_x >= abs_y)
		ft_find_draw_col(map, p1_x_y, p2_x_y, color);
	if (abs_x <= abs_y)
		ft_find_draw_line(map, p1_x_y, p2_x_y, color);
}
