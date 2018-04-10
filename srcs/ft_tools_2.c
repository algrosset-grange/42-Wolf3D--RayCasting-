/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_locate_player(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->nb_line)
	{
		y = 0;
		while (y < map->nb_colo)
		{
			if (map->tab[x][y] == 1)
			{
				map->player_pos_x = x;
				map->player_pos_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_wolf_img_clear(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			ft_img_put_pixel(map, x, y, 0);
			y++;
		}
		x++;
	}
}

void	ft_ajust_angle(t_map *map)
{
	if (map->angle_actu >= 360)
		map->angle_actu -= 360;
	else if (map->angle_actu < 0)
		map->angle_actu += 360;
}

void	ft_ver_line(t_map *map)
{
	int p_sky[2];
	int	p1_x_y[2];
	int	p2_x_y[2];

	map->draw_start = map->h / 2 - map->height_wall / 2 - 1;
	if (map->draw_start < 0)
		map->draw_start = 0;
	map->draw_end = map->h / 2 + map->height_wall / 2;
	if (map->draw_end >= map->h)
		map->draw_end = map->h - 1;
	p_sky[0] = map->y_w;
	p_sky[1] = 0;
	p1_x_y[0] = map->y_w;
	p2_x_y[0] = map->y_w;
	p1_x_y[1] = map->draw_start;
	p2_x_y[1] = map->draw_end;
	ft_put_line(map, p_sky, p1_x_y, C_SKY);
	ft_put_line(map, p1_x_y, p2_x_y, map->color);
}
