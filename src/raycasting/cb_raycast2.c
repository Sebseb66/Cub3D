/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:13:25 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:10:57 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_set_honrizontal_val(t_game *game)
**		- Set the horizontal value
*/

void	ft_set_honrizontal_val(t_game *game)
{
	game->ray->dist_h = 100000;
	game->ray->hor_x = game->pl_x;
	game->ray->hor_y = game->pl_y;
	game->ray->depoffield = 0;
	game->ray->a_tan = -1 / tan(game->ray->ray_a);
}

/*	ft_line_honrizontal(t_game *game)
**		- Set the horizontal line
**		- Launch the horizontal ray
*/

void	ft_line_honrizontal(t_game *game)
{
	ft_set_honrizontal_val(game);
	if (game->ray->ray_a > M_PI)
	{
		game->ray->ray_y = (((int)game->pl_y / 128) * 128) - 0.0001;
		game->ray->ray_x = (game->pl_y - game->ray->ray_y)
			* game->ray->a_tan + game->pl_x;
		game->ray->y_o = -128;
		game->ray->x_o = -game->ray->y_o * game->ray->a_tan;
	}
	if (game->ray->ray_a < M_PI)
	{
		game->ray->ray_y = (((int)game->pl_y / 128) * 128) + 128;
		game->ray->ray_x = (game->pl_y - game->ray->ray_y)
			* game->ray->a_tan + game->pl_x;
		game->ray->y_o = 128;
		game->ray->x_o = -game->ray->y_o * game->ray->a_tan;
	}
	if (game->ray->ray_a == 0 || game->ray->ray_a == M_PI)
	{
		game->ray->ray_x = game->pl_x;
		game->ray->ray_y = game->pl_y;
		game->ray->depoffield = game->height;
	}
	ft_honrizontal_wall(game);
}

/*	ft_honrizontal_wall(t_game *game)
**		- Get the horizontal wall
**		- While the ray is not at the end of the field
*/

void	ft_honrizontal_wall(t_game *game)
{
	while (game->ray->depoffield < game->height)
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
			game->ray->hor_x = game->ray->ray_x;
			game->ray->hor_y = game->ray->ray_y;
			game->ray->dist_h = ft_get_distance(game, game->ray->hor_x,
					game->ray->hor_y);
			game->ray->depoffield = game->height;
		}
		else
		{
			game->ray->ray_x += game->ray->x_o;
			game->ray->ray_y += game->ray->y_o;
			game->ray->depoffield += 1;
		}
	}
}
