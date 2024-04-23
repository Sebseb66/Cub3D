/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:40:05 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:23:39 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_rgb_hex(int r, int g, int b)
**		- Convert the RGB to hex
*/

long	ft_rgb_hex(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

/*	ft_set_pixel(t_img *img, int max_x, int max_y, t_map *map)
**		- Set the pixel
*/

void	ft_set_pixel(t_img *img, int max_x, int max_y, t_map *map)
{
	int		x;
	int		y;
	long	color;

	color = ft_rgb_hex(map->ceiling[0], map->ceiling[1], map->ceiling[2]);
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
		if (y == max_y / 2)
			color = ft_rgb_hex(map->floor[0], map->floor[1], map->floor[2]);
	}
}

/*	mlx_put_pixel(t_img *img, int x, int y, long color)
**		- Put the pixel
*/

void	mlx_put_pixel(t_img *img, int x, int y, long color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = img->addr + (y * img->line + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}
