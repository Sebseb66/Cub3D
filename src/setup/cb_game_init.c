/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:34:26 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/08 00:46:01 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_game(t_map *map)
**		- Initialize the game
**		- Set the display size
*/

void	ft_game(t_map *map)
{
	map->game->dis_w = WIDTH;
	map->game->dis_h = HEIGHT;
	map->game->width = ft_get_longuest(map->map);
	map->game->height = ft_len_tab(map->map);
	ft_beggin(map->game, map);
}

/*	ft_get_longuest(char **map)
**		- Get the longuest line of the map
**		- Return the longuest line
*/

int	ft_get_longuest(char **map)
{
	unsigned int	check;
	unsigned int	i;

	check = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (check < ft_strlen(map[i]))
			check = ft_strlen(map[i]);
		i++;
	}
	return (check);
}

/*	ft_beggin(t_game *game, t_map *map)
**		- Initialize the game
**		- Set the mlx and the window
**		- Set the texture
**		- Draw the map
**		- Set the hooks
*/

void	ft_beggin(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->dis_w, game->dis_h, "Cobe3D");
	ft_get_draw_texture(game, map);
	map->error = ft_draw_map(game, map);
	if (map->error > 0)
		return (ft_free_texture(map));
	mlx_loop_hook(game->mlx, ft_hooks, map);
	mlx_hook(game->win, 17, 1, ft_exit, map);
	mlx_hook(game->win, 2, 1, ft_controls, map);
	mlx_loop(game->mlx);
}
