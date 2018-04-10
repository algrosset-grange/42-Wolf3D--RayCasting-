/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:18:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/25 11:18:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <stdio.h>

# define MANDEL_NB_COLOR 78
# define KEY_C 8
# define KEY_ECHAP 53
# define KEY_MORE 69
# define KEY_LESS 78
# define KEY_EQUA 81
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define MOTION_MOUSE 6
# define DESTROY_NOTIFY	17

# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE_MASK (1L<<1)
# define BUTTON_PRESS_MASK (1L<<2)
# define BUTTON_RELEASE_MASK (1L<<3)
# define MOTION_BUTTON_MASK (1L<<13)
# define STRUCTURE_NOTIFY_MASK (1L<<17)

# define C_YELLOW_WEST 0xFFFF00
# define C_RED_NORTH 0xFF0000
# define C_GREEN_EST 0x00FF00
# define C_BLUE_SOUTH 0x0000FF
# define C_SKY 0xACE5F0

# define C_WHITE_GROUND 0xFFFFFF

# define SIZE_BLOCK 64

typedef struct		s_map
{
	void			*ptr;
	void			*win;
	int				w;
	int				h;

	int				**tab;

	int				nb_line;
	int				nb_colo;

	void			*img_ptr;
	char			*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;

	float			player_pos_x;
	float			player_pos_y;
	double			dist_projec;
	double			angl_ecart;
	double			angle_base;
	double			angle_actu;
	float			size_case;

	int				y_w;

	int				etat_x;
	int				etat_y;

	int				mur_gd_ou_hb;
	int				color;

	int				height_wall;
	int				draw_start;
	int				draw_end;

	float			inc_x;
	float			inc_y;
	float			point_x;
	float			point_y;
	float			dist_hori;
	float			dist_verti;
	float			dist_incorrect;
	float			dist_correct;
	int				field_vision;
	float			new_pos_x;
	float			new_pos_y;

}					t_map;

t_map				*ft_read_doc(const char *doc);

t_map				*ft_new_map(int nb_l, int nb_c);
void				ft_free_map(t_map **map);

void				ft_wolf_img_initi(t_map *map);
void				ft_wolf_img(t_map *map);

void				ft_mlx(t_map *map);

void				ft_img_put_pixel(t_map *map, int x, int y, int rgb);
void				ft_img_put_pixel_tab(t_map *map, int *x_y, int *rgb);

void				ft_put_line(t_map *map, int *p1_x_y, int *p2_x_y,
						int color);

void				ft_draw_line_c1(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_line_c2(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_line_c3(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_line_c4(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);

void				ft_draw_col_c1(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_col_c2(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_col_c3(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);
void				ft_draw_col_c4(t_map *map, int *p1_x_y,
						int *p2_x_y, int color);

void				ft_wolf_img_find_dist_hori(t_map *map);
void				ft_wolf_img_find_dist_verti(t_map *map);

int					ft_inside_map(t_map *map);
int					ft_is_wall(t_map *map);
float				ft_get_dist(t_map *map);

void				ft_play_move(t_map *map, int speed);
void				ft_play_rotate_left(t_map *map);
void				ft_play_rotate_right(t_map *map);

void				ft_locate_player(t_map *map);
void				ft_wolf_img_clear(t_map *map);
void				ft_ajust_angle(t_map *map);
void				ft_ver_line(t_map *map);

#endif
