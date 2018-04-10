/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 13:24:05 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/31 13:24:06 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_complet_tab_p2(int c, char **line, t_map *map, int *begin)
{
	char	**tab_w;
	int		l;

	l = 0;
	tab_w = ft_strsplit(*line, ' ');
	while (l < map->nb_line)
	{
		if (!ft_isdigit(tab_w[l][0]))
			return (0);
		if (!ft_strcmp(tab_w[l], "1"))
			(*begin)++;
		map->tab[l][c] = ft_atoi(tab_w[l]);
		l++;
	}
	return (1);
}

/*
**	char = un caractere
**	char * = un mot/ chaine de caractere
**	char ** = tableau de mot
**	char *** = tableau a 2 dimension de m
*/

static int	ft_complet_tab_p1(const char *doc, t_map *map, char **line)
{
	int	b_c;
	int	c;
	int	fd;
	int	begin;

	b_c = 1;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (1);
	c = 0;
	begin = 0;
	while (c < map->nb_colo && b_c == 1)
	{
		b_c = ft_get_next_line(fd, line);
		if (b_c == -1 || !ft_complet_tab_p2(c, line, map, &begin) || begin > 1)
			return (1);
		c++;
	}
	close(fd);
	if (!begin)
		return (1);
	return (0);
}

static int	ft_get_nb_line(const char *doc)
{
	int		l;
	int		nb_c;
	int		fd;
	char	*line;

	l = 1;
	nb_c = 0;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (0);
	l = ft_get_next_line(fd, &line);
	nb_c = ft_count_word(line, ' ');
	while ((l = ft_get_next_line(fd, &line)) > 0)
		if (ft_count_word(line, ' ') != nb_c)
			return (0);
	close(fd);
	return (nb_c);
}

static int	ft_get_nb_colo(const char *doc, char **line)
{
	int		l;
	int		nb_l;
	int		fd;

	nb_l = 0;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((l = ft_get_next_line(fd, line)) > 0)
	{
		if (l == 1)
			nb_l++;
		if (l == -1)
			return (0);
	}
	close(fd);
	return (nb_l);
}

/*
** 	en informatique, les colone sont sur les ordonnées (y)
**	et les lignes sur absice (x) (contrairement au tableau habituel)
**
**	exemple :
**	0 0 0
**	0 0 0
**	vaut (2,3) en tab informatique
*/

t_map		*ft_read_doc(const char *doc)
{
	t_map	*map;
	char	*line;
	int		nb_l;
	int		nb_c;

	map = NULL;
	if ((nb_c = ft_get_nb_colo(doc, &line)) == 0 ||
		(nb_l = ft_get_nb_line(doc)) == 0 ||
		(map = ft_new_map(nb_l, nb_c)) == NULL ||
		(ft_complet_tab_p1(doc, map, &line)))
	{
		ft_free_map(&map);
		return (NULL);
	}
	return (map);
}
