/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:41:28 by vabatist          #+#    #+#             */
/*   Updated: 2025/04/02 12:07:09 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h> // open and close files
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char		**data;
	int			rows;
	int			cols;
	int			count_p;
	int			count_e;
	int			count_c;
}				t_map;

typedef struct s_flood
{
	int			collectibles;
	int			exit_found;
}				t_flood;

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectible;
	void		*exit;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	t_map		map;
	int			count_moves;
}				t_game;

typedef struct s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

# define SPRITE_SIZE 64

// events
enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

// map components
# define VALID_CHARS "01CEP"

// error
void			error_exit(const char *message);
void			error_exit_map(const char *message, t_map *map);
void			error_exit_game(const char *message, t_game *game);

// frees
void			free_map(t_map *map);
void			free_copy(char **copy, int rows);
void			free_textures(t_game *game);
void			free_game(t_game *game);

// map_init
void			init_map(int argc, char **argv, t_map *map);
void			check_file_extension(const char *filename);
int				count_lines_in_file(int fd);
int				open_map_file(const char *filename);
void			allocate_map_data(t_map *map);

// map_read
void			read_map_from_file(const char *filename, t_map *map);
void			read_map_line(int fd, t_map *map, int index);

// map_validation
void			validate_map(t_map *map);
void			check_rectangular(t_map *map);
void			count_map_elements(t_map *map);
void			validate_map_format(t_map *map);
void			validate_borders(t_map *map);

// map_validation_aux
void			validate_path(t_map *map);
void			find_player_and_fill(char **copy, t_map *map, t_flood *flood);
void			copy_map(char **copy, t_map *map);
void			flood_fill(char **map, int x, int y, t_flood *flood);
int				is_valid_char(char c);

// render
int				render_map(void *param);
void			render_tile(t_game *game, char tile, int x, int y);
void			load_textures(t_game *game);

// input
void			move_player(t_game *game, t_coordinates current,
					t_coordinates destination);
void			move_left(t_game *game);
void			move_up(t_game *game);
void			move_rigth(t_game *game);
void			move_down(t_game *game);

// input aux
void			check_restrictions(t_game *game, t_coordinates current,
					t_coordinates destination);
t_coordinates	get_player_position(t_map map);

// so_long
int				handle_keypress(int keycode, void *param);
void			open_door(t_game *game);

#endif