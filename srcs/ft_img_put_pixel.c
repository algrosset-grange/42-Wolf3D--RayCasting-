/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:25:24 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/14 14:25:26 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** printf("img->data[i] = %hhu\n", img->data[i]);
*/

void	ft_img_put_pixel(t_map *map, int x, int y, int rgb)
{
	int		i;

	if (0 <= x && x < map->w &&
		0 <= y && y < map->h)
	{
		i = x * 4 + y * map->img_size_line;
		map->img_data[i + 2] = rgb / (0x10000);
		rgb %= 0x10000;
		map->img_data[i + 1] = rgb / 0x100;
		rgb %= 0x100;
		map->img_data[i] = rgb;
		map->img_data[i + 3] = 0;
	}
}

void	ft_img_put_pixel_tab(t_map *map, int *x_y, int *rgb)
{
	int i;

	if (0 < x_y[0] && x_y[0] < map->w &&
		0 < x_y[1] && x_y[1] < map->h)
	{
		i = x_y[0] * 4 + x_y[1] * map->img_size_line;
		map->img_data[i] = rgb[2];
		map->img_data[i + 1] = rgb[1];
		map->img_data[i + 2] = rgb[0];
		map->img_data[i + 3] = 0;
	}
}

int		ft_color_div(int color, int div)
{
	int rgb[3];

	rgb[0] = (color / (0x10000)) / div;
	color %= 0x10000;
	rgb[1] = (color / 0x100) / div;
	color %= 0x100;
	rgb[2] = color / div;
	return (rgb[0] * (0x10000) + rgb[1] * (0x100) + rgb[2]);
}

int		ft_get_px_color(t_map *map, int x, int y)
{
	int i;
	int	rgb;

	rgb = -1;
	if (0 <= x && x < map->h &&
		0 <= y && y < map->w)
	{
		i = x * 4 + y * map->img_size_line;
		rgb = map->img_data[i];
		rgb += (map->img_data[i + 1] * 0x100);
		rgb += (map->img_data[i + 2] * 0x10000);
	}
	return (rgb);
}
