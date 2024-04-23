/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:10:03 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:09:20 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_raycaster(t_game *game)
**		- Raycasting function
**		- Set the ray angle
**		- Set the ray distance
**		- Set the ray value
*/

void	ft_raycaster(t_game *game)
{
	game->ray->rays = -1;
	game->ray->ray_a = game->cast->pa - 0.0174533 * 30;
	ft_set_value(game);
	while (++game->ray->rays < game->ray->n_of_rays)
	{
		ft_line_honrizontal(game);
		ft_line_vertical(game);
		ft_check_distance(game);
		ft_set_ray_val(game);
	}
}

/*	ft_set_value(t_game *game)
**		- Set the ray angle value
*/

void	ft_set_value(t_game *game)
{
	if (game->ray->ray_a < 0)
		game->ray->ray_a += 2 * M_PI;
	if (game->ray->ray_a > 2 * M_PI)
		game->ray->ray_a -= 2 * M_PI;
}

/*	ft_get_distance(t_game *g, double bx, double by)
**		- Get the distance between the player and the wall
**		- Return the distance
*/

double	ft_get_distance(t_game *g, double bx, double by)
{
	double	ax;
	double	ay;

	ax = g->pl_x;
	ay = g->pl_y;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

/*	ft_set_ray_val(t_game *game)
**		- Set the ray value
**		- And draw the walls
*/

void	ft_set_ray_val(t_game *game)
{
	ft_set_cos(game);
	ft_set_render(game);
	ft_draw_walls(game);
	game->ray->ray_a += 0.0174533 / 8;
	ft_set_value(game);
}
