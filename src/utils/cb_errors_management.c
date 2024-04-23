/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_errors_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:19:49 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:21:46 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	free_tab(char **tab)
**		- Free the tab
*/

void	free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab && tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

/*	ft_endgame(t_map *map)
**		- Free the map
**		- Close the file
**		- Free the struct
*/

void	ft_endgame(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->so)
		free(map->so);
	if (map->error != 2)
		close(map->fd);
	if (map->map != NULL)
	{
		free_tab(map->map);
		free(map->game->ray);
		free(map->game->cast);
		free(map->game->dl);
	}
	ft_free_struct(map);
}

/*	ft_free_struct(t_map *map)
**		- Free the struct
*/

void	ft_free_struct(t_map *map)
{
	if (map->error == 0)
	{
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_no->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_so->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_ea->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_we->mlx_img);
	}
	if (map->error == 0 || map->error == 3)
		free(map->game->texture);
	if (map->map != NULL)
		free(map->game);
	free(map);
}

/*	ft_destroy_img(t_game *game, int i)
**		- Destroy the image
*/

void	ft_destroy_img(t_game *game, int i)
{
	if (i >= 1)
		mlx_destroy_image(game->mlx, game->texture->wall_no->mlx_img);
	if (i >= 2)
		mlx_destroy_image(game->mlx, game->texture->wall_so->mlx_img);
	if (i >= 3)
		mlx_destroy_image(game->mlx, game->texture->wall_we->mlx_img);
	if (i >= 4)
		mlx_destroy_image(game->mlx, game->texture->wall_ea->mlx_img);
}

/*	ft_exit(t_map *map)
**		- Exit the game
**		- Free the struct
*/

int	ft_exit(t_map *map)
{
	ft_destroy_img(map->game, 4);
	mlx_destroy_window(map->game->mlx, map->game->win);
	mlx_destroy_image(map->game->mlx, map->game->texture->background->mlx_img);
	mlx_destroy_display(map->game->mlx);
	free(map->game->mlx);
	if (map->no)
		free(map->no);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->so)
		free(map->so);
	if (map->error != 2)
		close(map->fd);
	if (map->map != NULL)
	{
		free_tab(map->map);
		free(map->game->ray);
		free(map->game->cast);
		free(map->game->dl);
	}
	ft_free_wall(map);
	exit(0);
}
