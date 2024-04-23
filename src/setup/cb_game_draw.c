/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_game_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:43:27 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:16:01 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_draw_map(t_game *game, t_map *map)
**		- Get all XPM files and draw the map
**		- Return 3 if a texture is not loading
*/

int	ft_draw_map(t_game *game, t_map *map)
{
	ft_draw_player(game, map->map);
	game->texture->wall_no->mlx_img = mlx_xpm_file_to_image(game->mlx,
			map->no, &game->texture->wall_no->x,
			&game->texture->wall_no->y);
	if (game->texture->wall_no->mlx_img == NULL)
		return (printf("Error\n'NO' Texture not loading\n"), 3);
	game->texture->wall_so->mlx_img = mlx_xpm_file_to_image(game->mlx,
			map->so, &game->texture->wall_so->x,
			&game->texture->wall_so->y);
	if (game->texture->wall_so->mlx_img == NULL)
		return (ft_destroy_img(game, 1),
			printf("Error\n'SO' Texture not loading\n"), 3);
	game->texture->wall_we->mlx_img = mlx_xpm_file_to_image(game->mlx,
			map->we, &game->texture->wall_we->x,
			&game->texture->wall_we->y);
	if (game->texture->wall_we->mlx_img == NULL)
		return (ft_destroy_img(game, 2),
			printf("Error\n'WE' Texture not loading\n"), 3);
	game->texture->wall_ea->mlx_img = mlx_xpm_file_to_image(game->mlx,
			map->ea, &game->texture->wall_ea->x, &game->texture->wall_ea->y);
	if (game->texture->wall_ea->mlx_img == NULL)
		return (ft_destroy_img(game, 3),
			printf("Error\n'EA' Texture not loading\n"), 3);
	ft_get_addr(game->texture);
	return (0);
}

/*	ft_get_addr(t_textures *tex)
**		- Get the address of the texture
*/

void	ft_get_addr(t_textures *tex)
{
	tex->wall_no->addr = mlx_get_data_addr(tex->wall_no->mlx_img,
			&tex->wall_no->bpp, &tex->wall_no->line, &tex->wall_no->endian);
	tex->wall_so->addr = mlx_get_data_addr(tex->wall_so->mlx_img,
			&tex->wall_so->bpp, &tex->wall_so->line, &tex->wall_so->endian);
	tex->wall_ea->addr = mlx_get_data_addr(tex->wall_ea->mlx_img,
			&tex->wall_ea->bpp, &tex->wall_ea->line, &tex->wall_ea->endian);
	tex->wall_we->addr = mlx_get_data_addr(tex->wall_we->mlx_img,
			&tex->wall_we->bpp, &tex->wall_we->line, &tex->wall_we->endian);
}

/*	ft_draw_player(t_game *game, char **map)
**		- Get the player position and draw it
*/

void	ft_draw_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				game->pl_x = j * 128 + 64;
				game->pl_y = i * 128 + 64;
			}
			j++;
		}
		i++;
	}
}
