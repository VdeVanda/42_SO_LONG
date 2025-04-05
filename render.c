/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:28 by vabatist          #+#    #+#             */
/*   Updated: 2025/04/02 17:01:03 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Renders the map on the window.
 */
int	render_map(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			render_tile(game, game->map.data[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}

/**
 * Helper function for the render_map function.
 */
void	render_tile(t_game *game, char tile, int x, int y)
{
	t_textures	*textures;

	textures = &game->textures;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, textures->wall, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, textures->floor, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, textures->collectible, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, textures->exit, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, textures->player, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
}

/**
 * Loads the textures used in the game.
 */
void	load_textures(t_game *game)
{
	t_textures	*textures;
	int			height;
	int			width;

	textures = &game->textures;
	height = SPRITE_SIZE;
	width = SPRITE_SIZE;
	textures->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&height, &width);
	textures->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &height, &width);
	textures->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&height, &width);
	textures->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &height, &width);
	textures->exit = mlx_xpm_file_to_image(game->mlx, "textures/close_door.xpm",
			&height, &width);
	if (!textures->wall || !textures->floor || !textures->player
		|| !textures->collectible || !textures->exit)
		error_exit_game("Failed to load textures", game);
}
