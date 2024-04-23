/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:32 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:18:09 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_init_struct(char *path)
**		- Initialize the struct
**		- Return the struct
*/

t_map	*ft_init_struct(char *path)
{
	t_map		*map;

	map = malloc(sizeof(t_map));
	map->error = 0;
	map->fd = open(path, O_RDONLY);
	if (!map->fd)
		return (map->error = 2, map);
	ft_init_null(map);
	map->map = NULL;
	if (ft_get_map(map) == 1)
		return (map->error = 1, map);
	map->map = ft_setmap(map->fd);
	if (map->map == NULL)
		return (map->error = 1, map);
	ft_malloc_game(map);
	return (map);
}

/*	ft_malloc_game(t_map *map)
**		- Malloc the game struct
*/

void	ft_malloc_game(t_map *map)
{
	map->game = malloc(sizeof(t_game));
	map->game->cast = ft_init_cast(map);
	map->game->dl = ft_line_init();
	map->game->ray = ft_raycast_init();
	map->game->texture = malloc(sizeof(t_textures));
	ft_malloc_img(map->game->texture);
}

/*	ft_init_cast(t_map *map)
**		- Initialize the cast struct
**		- Return the cast struct
*/

t_cast	*ft_init_cast(t_map *map)
{
	t_cast	*cast;

	cast = malloc(sizeof(t_cast));
	if (ft_check_points('N', map->map))
		cast->pa = 3 * M_PI_2;
	else if (ft_check_points('W', map->map))
		cast->pa = 2 * M_PI_2;
	else if (ft_check_points('S', map->map))
		cast->pa = M_PI_2;
	else
		cast->pa = 0;
	cast->map_x = 0;
	cast->map_y = 0;
	cast->pd_x = 0;
	cast->pd_y = 0;
	cast->pd_x_strafe = 0;
	cast->pd_y_strafe = 0;
	cast->line_hight = 0;
	cast->line_offset = 0;
	cast->x_off = 0;
	cast->y_off = 0;
	cast->x_off_strafe = 0;
	cast->y_off_strafe = 0;
	cast->map = map->map;
	return (cast);
}

/*	ft_line_init(void)
**		- Initialize the draw line struct
**		- Return the draw line struct
*/

t_draw_line	*ft_line_init(void)
{
	t_draw_line	*dl;

	dl = malloc(sizeof(t_draw_line));
	dl->tx = 0;
	dl->ty = 0;
	dl->dy = 0;
	dl->fix_ra = 0;
	dl->pixel = 0;
	dl->color = 0;
	dl->begin_x = 0;
	dl->begin_y = 0;
	dl->end_x = 0;
	dl->end_y = 0;
	return (dl);
}

/*	ft_raycast_init(void)
**		- Initialize the raycast struct
**		- Return the raycast struct
*/

t_ray	*ft_raycast_init(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->rays = 0;
	ray->depoffield = 0;
	ray->ray_a = 0;
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->x_o = 0;
	ray->y_o = 0;
	ray->dist_h = 0;
	ray->dist_v = 0;
	ray->hor_x = 0;
	ray->hor_y = 0;
	ray->ver_x = 0;
	ray->ver_y = 0;
	ray->final_d = 0;
	ray->n_of_rays = 480;
	return (ray);
}
