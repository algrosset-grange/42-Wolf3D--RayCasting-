/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_make_win(t_map *map)
{
	map->w = 1000;
	map->h = 1000;
	if (((map->ptr = mlx_init()) == NULL) ||
		((map->img_ptr = mlx_new_image(map->ptr, map->w, map->h))
			== NULL) || ((map->win =
			mlx_new_window(map->ptr, map->w, map->h, "wolf3d")) == NULL))
		return (1);
	map->img_data = mlx_get_data_addr(map->img_ptr, &(map->img_bits_per_pixel),
		&(map->img_size_line), &(map->img_endian));
	return (0);
}

static int	ft_alloc_tab(t_map *map, int nb_l, int nb_c)
{
	int	i;

	map->tab = NULL;
	if ((map->tab = (int **)ft_memalloc(sizeof(int *) * nb_l))
		== NULL)
		return (1);
	i = 0;
	while (i < nb_l)
	{
		map->tab[i] = NULL;
		if ((map->tab[i] =
			(int *)ft_memalloc(sizeof(int) * nb_c))
			== NULL)
			return (1);
		i++;
	}
	return (0);
}

t_map		*ft_new_map(int nb_l, int nb_c)
{
	t_map	*map;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL ||
		ft_alloc_tab(map, nb_l, nb_c) ||
		ft_make_win(map))
		return (NULL);
	map->nb_line = nb_l;
	map->nb_colo = nb_c;
	return (map);
}
