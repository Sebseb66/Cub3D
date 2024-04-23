/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:01:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:23:12 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_check_collision(char c)
**		- Check if the player can move
**		- Return 1 if the player can move
*/

bool	ft_check_collision(char c)
{
	if (c == '1' || c == 'D')
		return (false);
	return (true);
}

/*	ft_offset(t_game *game)
**		- Set the offset for the player
**		- Offset is the distance raycasted
*/

void	ft_offset(t_game *game)
{
	game->cast->pd_x = cos(game->cast->pa) * 6;
	game->cast->pd_y = sin(game->cast->pa) * 6;
	if (game->cast->pd_x < 0)
		game->cast->x_off = -20;
	else
		game->cast->x_off = 20;
	if (game->cast->pd_y < 0)
		game->cast->y_off = -20;
	else
		game->cast->y_off = 20;
	game->cast->pd_x_strafe = cos(game->cast->pa + M_PI_2) * 6;
	game->cast->pd_y_strafe = sin(game->cast->pa + M_PI_2) * 6;
	if (game->cast->pd_x_strafe < 0)
		game->cast->x_off_strafe = -20;
	else
		game->cast->x_off_strafe = 20;
	if (game->cast->pd_y_strafe < 0)
		game->cast->y_off_strafe = -20;
	else
		game->cast->y_off_strafe = 20;
}
