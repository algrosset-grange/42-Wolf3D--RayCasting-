/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_wolf_img_find_walls(t_map *map)
{
	map->dist_verti = 0;
	map->dist_hori = 0;
	ft_wolf_img_find_dist_hori(map);
	ft_wolf_img_find_dist_verti(map);
	map->dist_incorrect = map->dist_verti;
	map->mur_gd_ou_hb = 0;
	if (map->dist_verti > map->dist_hori)
	{
		map->dist_incorrect = map->dist_hori;
		map->mur_gd_ou_hb = 1;
	}
}

static void	ft_wolf_img_color(t_map *map)
{
	map->color = C_WHITE_GROUND;
	if (map->mur_gd_ou_hb == 1 && map->etat_x == 1)
		map->color = C_RED_NORTH;
	else if (map->mur_gd_ou_hb == 1 && map->etat_x == -1)
		map->color = C_BLUE_SOUTH;
	else if (map->mur_gd_ou_hb == 0 && map->etat_y == 1)
		map->color = C_YELLOW_WEST;
	else if (map->mur_gd_ou_hb == 0 && map->etat_y == -1)
		map->color = C_GREEN_EST;
}

static void	ft_wolf_img_affection(t_map *map)
{
	map->angle_actu = map->angle_base;
	map->angle_actu += (map->field_vision / 2.0);
	map->angle_actu -= ((float)map->y_w * (float)map->angl_ecart);
	ft_ajust_angle(map);
	if (90 < map->angle_actu && map->angle_actu <= 270)
		map->etat_y = -1;
	else
		map->etat_y = 1;
	if (0 < map->angle_actu && map->angle_actu <= 180)
		map->etat_x = 1;
	else
		map->etat_x = -1;
}

void		ft_wolf_img(t_map *map)
{
	ft_wolf_img_clear(map);
	map->y_w = 0;
	while (map->y_w < map->w)
	{
		ft_wolf_img_affection(map);
		ft_wolf_img_find_walls(map);
		ft_wolf_img_color(map);
		map->dist_correct = map->dist_incorrect
			* ft_cos_deg(fabs(map->angle_actu - map->angle_base));
		map->height_wall = map->h;
		if (map->dist_correct)
			map->height_wall = abs(map->h
				- (int)floor(map->dist_correct));
		map->height_wall = map->size_case
			* map->dist_projec / map->dist_correct;
		ft_ver_line(map);
		map->y_w++;
	}
	mlx_put_image_to_window(map->ptr, map->win, map->img_ptr, 0, 0);
}

void		ft_wolf_img_initi(t_map *map)
{
	ft_locate_player(map);
	system("afplay ./music/Sneaky_Snitch_-_Kevin_MacLeod.mp3 &");
	map->size_case = 100;
	map->player_pos_x = map->player_pos_x
		* map->size_case + (map->size_case / 2);
	map->player_pos_y = map->player_pos_y
		* map->size_case + (map->size_case / 2);
	map->field_vision = 70;
	map->dist_projec = (map->w / 2) / ft_tan_deg(map->field_vision / 2);
	map->angl_ecart = map->field_vision / (double)map->w;
	map->angle_base = 90;
	ft_wolf_img(map);
	mlx_put_image_to_window(map->ptr, map->win, map->img_ptr, 0, 0);
}
