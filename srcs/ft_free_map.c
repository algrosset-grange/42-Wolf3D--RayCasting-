/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:50 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:53 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free_map(t_map **map)
{
	if ((*map) != NULL)
	{
		if ((*map)->img_ptr != NULL)
			mlx_destroy_image((*map)->ptr, (*map)->img_ptr);
		ft_memdel((void **)(*map)->tab);
		ft_memdel((void **)(*map));
		ft_memdel((void **)map);
		system("killall afplay");
	}
}
