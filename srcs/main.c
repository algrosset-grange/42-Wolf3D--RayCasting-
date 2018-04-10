/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:19 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:21 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int argc, char **argv)
{
	char	*c;
	t_map	*map;

	map = NULL;
	c = NULL;
	if (argc < 2)
	{
		ft_putstr("usage: ./wolf3d source_file\n");
		return (0);
	}
	if ((map = ft_read_doc(argv[1])) == NULL)
	{
		ft_putstr("error : un fichier valide doit etre fournie\n");
		return (0);
	}
	ft_wolf_img_initi(map);
	ft_mlx(map);
	return (0);
}
