/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:16:02 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:11:59 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_set_vertical_val(t_game *game)
**		- Set the vertical value
*/

void	ft_set_vertical_val(t_game *game)
{
	game->ray->dist_v = 100000;
	game->ray->ver_x = game->pl_x;
	game->ray->ver_y = game->pl_y;
	game->ray->depoffield = 0;
	game->ray->n_tan = -tan(game->ray->ray_a);
}

/*	ft_line_vertical(t_game *game)
**		- Set the vertical line
**		- Launch the vertical ray
*/

void	ft_line_vertical(t_game *game)
{
	ft_set_vertical_val(game);
	if (game->ray->ray_a > M_PI_2 && game->ray->ray_a < 3 * M_PI_2)
	{
		game->ray->ray_x = (((int)game->pl_x / 128) * 128) - 0.0001;
		game->ray->ray_y = (game->pl_x - game->ray->ray_x)
			* game->ray->n_tan + game->pl_y;
		game->ray->x_o = -128;
		game->ray->y_o = -game->ray->x_o * game->ray->n_tan;
	}
	if (game->ray->ray_a < M_PI_2 || game->ray->ray_a > 3 * M_PI_2)
	{
		game->ray->ray_x = (((int)game->pl_x / 128) * 128) + 128;
		game->ray->ray_y = (game->pl_x - game->ray->ray_x)
			* game->ray->n_tan + game->pl_y;
		game->ray->x_o = 128;
		game->ray->y_o = -game->ray->x_o * game->ray->n_tan;
	}
	if (game->ray->ray_a == 0 || game->ray->ray_a == M_PI)
	{
		game->ray->ray_x = game->pl_x;
		game->ray->ray_y = game->pl_y;
		game->ray->depoffield = game->width;
	}
	ft_vertical_wall(game);
}

/*	ft_vertical_wall(t_game *game)
**		- Set the vertical wall
**		- Launch the vertical ray to find the wall
*/

void	ft_vertical_wall(t_game *game)
{
	while (game->ray->depoffield < game->width)
	{
		game->cast->map_x = (int)game->ray->ray_x / 128;
		game->cast->map_y = (int)game->ray->ray_y / 128;
		if (game->cast->map_y < game->height && game->cast->map_x >= 0
			&& game->cast->map_y >= 0
			&& game->cast->map_x < (int)ft_strlen(
				game->cast->map[game->cast->map_y])
			&& (game->cast->map[game->cast->map_y][game->cast->map_x] == '1'
			|| game->cast->map[game->cast->map_y][game->cast->map_x] == 'D'))
		{
			game->ray->ver_x = game->ray->ray_x;
			game->ray->ver_y = game->ray->ray_y;
			game->ray->dist_v = ft_get_distance(game, game->ray->ver_x,
					game->ray->ver_y);
			game->ray->depoffield = game->width;
		}
		else
		{
			game->ray->ray_x += game->ray->x_o;
			game->ray->ray_y += game->ray->y_o;
			game->ray->depoffield += 1;
		}
	}
}

/*	ft_check_distance(t_game *game)
**		- Check the distance between the player and the wall
**		- Set the ray value
*/

void	ft_check_distance(t_game *game)
{
	if (game->ray->dist_v < game->ray->dist_h)
	{
		game->ray->shade = 0.5;
		game->ray->ray_x = game->ray->ver_x;
		game->ray->ray_y = game->ray->ver_y;
		game->ray->final_d = game->ray->dist_v;
	}
	if (game->ray->dist_h < game->ray->dist_v)
	{
		game->ray->shade = 1.0;
		game->ray->ray_x = game->ray->hor_x;
		game->ray->ray_y = game->ray->hor_y;
		game->ray->final_d = game->ray->dist_h;
	}
}
