/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:01:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/02/02 11:01:27 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_wolf_re_img(t_map *map)
{
	ft_wolf_img_clear(map);
	ft_wolf_img(map);
}

static int	ft_wolf_move(int keycode, t_map *map)
{
	if (keycode == KEY_LEFT)
		ft_play_rotate_left(map);
	if (keycode == KEY_RIGHT)
		ft_play_rotate_right(map);
	if (keycode == KEY_UP)
		ft_play_move(map, 20);
	if (keycode == KEY_DOWN)
		ft_play_move(map, -20);
	if (keycode == KEY_ECHAP)
	{
		ft_free_map(&map);
		exit(0);
	}
	ft_wolf_re_img(map);
	return (0);
}

static int	ft_exit(void *map)
{
	ft_free_map((t_map**)&map);
	exit(0);
}

void		ft_mlx(t_map *map)
{
	mlx_hook(map->win, KEY_PRESS, KEY_PRESS_MASK, ft_wolf_move, map);
	mlx_hook(map->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
		ft_exit, map);
	mlx_loop(map->ptr);
}
