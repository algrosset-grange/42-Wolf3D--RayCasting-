/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_get_first_horizontal_point(t_map *map)
{
	if (map->etat_x == 1)
		map->point_y = floor(map->player_pos_y / map->size_case)
			* map->size_case - 0.001;
	else
		map->point_y = floor(map->player_pos_y / map->size_case)
			* map->size_case + map->size_case;
	map->point_x = map->player_pos_x +
		(map->player_pos_y - map->point_y) / ft_tan_deg(map->angle_actu);
}

static void	ft_get_next_horizontal_point(t_map *map)
{
	map->point_x = map->point_x + map->inc_x;
	map->point_y = map->point_y + map->inc_y;
	map->dist_hori = ft_get_dist(map);
}

void		ft_wolf_img_find_dist_hori(t_map *map)
{
	ft_get_first_horizontal_point(map);
	if (map->etat_x == 1)
		map->inc_y = -map->size_case;
	else
		map->inc_y = +map->size_case;
	map->inc_x = -map->inc_y / ft_tan_deg(map->angle_actu);
	while (ft_inside_map(map) && !ft_is_wall(map))
		ft_get_next_horizontal_point(map);
	map->dist_hori = ft_get_dist(map);
}
