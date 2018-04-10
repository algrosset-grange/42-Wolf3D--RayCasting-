/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_inside_map(t_map *map)
{
	int		i;
	int		j;

	i = map->point_y / map->size_case;
	j = map->point_x / map->size_case;
	if (i < map->nb_line && map->point_y >= 0 && i >= 0
		&& j < map->nb_colo && map->point_x >= 0 && j >= 0)
		return (1);
	else
		return (0);
}

int			ft_is_wall(t_map *map)
{
	int		i;
	int		j;

	i = map->point_y / map->size_case;
	j = map->point_x / map->size_case;
	if (map->tab[i][j] > 1)
		return (1);
	else
		return (0);
}

float		ft_get_dist(t_map *map)
{
	float	pow1;
	float	pow2;
	float	sqrt1;

	pow1 = pow(map->player_pos_x - map->point_x, 2);
	pow2 = pow(map->player_pos_y - map->point_y, 2);
	sqrt1 = sqrt(pow1 + pow2);
	return (sqrt1);
}
