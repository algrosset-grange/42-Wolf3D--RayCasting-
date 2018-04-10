/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:19 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:21 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_inside_map_n_p(t_map *map)
{
	int		i;
	int		j;

	i = map->new_pos_y / map->size_case;
	j = map->new_pos_x / map->size_case;
	if (i < map->nb_line && map->new_pos_y >= 0 && i >= 0
		&& j < map->nb_colo && map->new_pos_x >= 0 && j >= 0)
		return (1);
	else
		return (0);
}

static int	ft_is_wall_n_p(t_map *map)
{
	int		i;
	int		j;

	i = map->new_pos_y / map->size_case;
	j = map->new_pos_x / map->size_case;
	if (map->tab[i][j] > 1)
		return (1);
	else
		return (0);
}

void		ft_play_move(t_map *map, int speed)
{
	map->new_pos_x = map->player_pos_x + ft_cos_deg(map->angle_base) * speed;
	map->new_pos_y = map->player_pos_y - ft_sin_deg(map->angle_base) * speed;
	if (ft_inside_map_n_p(map) && !ft_is_wall_n_p(map))
	{
		map->player_pos_x = map->new_pos_x;
		map->player_pos_y = map->new_pos_y;
	}
}

void		ft_play_rotate_left(t_map *map)
{
	map->angle_base = map->angle_base + 5.0;
	if (map->angle_base >= 360)
		map->angle_base -= 360;
	else if (map->angle_base < 0)
		map->angle_base += 360;
}

void		ft_play_rotate_right(t_map *map)
{
	map->angle_base = map->angle_base - 5.0;
	if (map->angle_base >= 360)
		map->angle_base -= 360;
	else if (map->angle_base < 0)
		map->angle_base += 360;
}
