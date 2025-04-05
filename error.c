/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:06:43 by vabatist          #+#    #+#             */
/*   Updated: 2025/03/26 16:30:07 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Exits the program with an error message.
 */
void	error_exit(const char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

/**
 * Exits the program with an error message.
 * Frees the map memory if it exists.
 */
void	error_exit_map(const char *message, t_map *map)
{
	if (map)
		free_map(map);
	error_exit(message);
}

/**
 * Exits the program with an error message.
 * Frees the game memory if it exists.
 */
void	error_exit_game(const char *message, t_game *game)
{
	if (game)
		free_game(game);
	error_exit(message);
}
