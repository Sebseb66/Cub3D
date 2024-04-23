/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:23 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:17:10 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_get_draw_texture(t_game *game, t_map *map)
**		- Paint the background
**		- Set the texture
*/

void	ft_get_draw_texture(t_game *g, t_map *m)
{
	g->texture->background->mlx_img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->texture->background->addr = mlx_get_data_addr(
			g->texture->background->mlx_img, &g->texture->background->bpp,
			&g->texture->background->line, &g->texture->background->endian);
	ft_set_pixel(g->texture->background, WIDTH, HEIGHT, m);
}
