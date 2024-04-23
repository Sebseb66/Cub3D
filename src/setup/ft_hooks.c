/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:57:25 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:20:33 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_hooks(t_map *map)
**		- Set the hooks
**		- Launch the raycaster
**		- Put the image to the window
*/

int	ft_hooks(t_map *map)
{
	ft_set_pixel(map->game->texture->background, WIDTH, HEIGHT, map);
	ft_raycaster(map->game);
	mlx_put_image_to_window(map->game->mlx, map->game->win,
		map->game->texture->background->mlx_img, 0, 0);
	return (0);
}

/*	ft_controls(int key, t_map *map)
**		- Set the controls
**		- Moove depending on the key
*/

int	ft_controls(int key, t_map *map)
{
	if (key == XK_Escape)
		ft_exit(map);
	if (key == XK_Left || key == XK_Right)
		ft_camera_move(map->game, key);
	ft_offset(map->game);
	if (key == 119 || key == 115)
		ft_move_front_back(map->game, key);
	if (key == 97 || key == 100)
		ft_move_vertical(map->game, key);
	return (0);
}

/*	ft_camera_move(t_game *game, int key)
**		- Move the camera
**		- Moove camera to the left or to the right
*/

void	ft_camera_move(t_game *game, int key)
{
	if (key == XK_Left)
	{
		game->cast->pa -= 0.1;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}
	else if (key == XK_Right)
	{
		game->cast->pa += 0.1;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}
}

/*	ft_move_front_back(t_game *game, int key)
**		- Move front or back
**		- Moove the player front or back
*/

void	ft_move_front_back(t_game *game, int key)
{
	if (key == 119)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x + game->cast->x_off) / 128]))
			game->pl_x += cos(game->cast->pa) * 10;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y + game->cast->y_off) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y += sin(game->cast->pa) * 10;
	}
	if (key == 115)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x - game->cast->x_off) / 128]))
			game->pl_x -= cos(game->cast->pa) * 10;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y - game->cast->y_off) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y -= sin(game->cast->pa) * 10;
	}
}

/*	ft_move_vertical(t_game *game, int key)
**		- Move vertical
**		- Moove the player to vertical or back
*/

void	ft_move_vertical(t_game *game, int key)
{
	if (key == 100)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x + game->cast->x_off_strafe) / 128]))
			game->pl_x += cos(game->cast->pa + M_PI_2) * 10;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y + game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y += sin(game->cast->pa + M_PI_2) * 10;
	}
	else if (key == 97)
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x - game->cast->x_off_strafe) / 128]))
			game->pl_x -= cos(game->cast->pa + M_PI_2) * 10;
		if (ft_check_collision(game->cast->map[(int)(game->pl_y
					- game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y -= sin(game->cast->pa + M_PI_2) * 10;
	}
}
