/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:55:08 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:22:04 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_free_texture(t_map *map)
**		- Free the texture
*/

void	ft_free_texture(t_map *map)
{
	mlx_destroy_window(map->game->mlx, map->game->win);
	mlx_destroy_image(map->game->mlx, map->game->texture->background->mlx_img);
	mlx_destroy_display(map->game->mlx);
	free(map->game->texture->wall_no);
	free(map->game->texture->wall_so);
	free(map->game->texture->wall_we);
	free(map->game->texture->wall_ea);
	free(map->game->texture->background);
	free(map->game->mlx);
	ft_endgame(map);
	exit(0);
}

/*	ft_free_wall(t_map *map)
**		- Free the wall texture
*/

void	ft_free_wall(t_map *map)
{
	free(map->game->texture->wall_no);
	free(map->game->texture->wall_so);
	free(map->game->texture->wall_we);
	free(map->game->texture->wall_ea);
	free(map->game->texture->background);
	free(map->game->texture);
	free(map->game);
	free(map);
}
