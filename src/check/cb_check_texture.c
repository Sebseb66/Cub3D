/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:32:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:04:41 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_get_texture(t_map *map, char *line, int k)
**		- Get the texture path
**		- Return true if the texture is valid
*/

int	ft_get_texture(t_map *map, char *line, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[k])
		if (line[k++] == '\t')
			return (printf("Error\nTab is not allowed..\n"), 1);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j])
		j++;
	if (ft_strncmp(line, "NO ", 3) == 0 && !map->no)
		map->no = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !map->so)
		map->so = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !map->we)
		map->we = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !map->ea)
		map->ea = ft_substr(line, i, j - 1);
	else
		return (printf("Error\nDuplicate NO,SE,WE or EA\n"), 1);
	return (0);
}

/*	ft_check_xpm(t_map *map)
**		- Check if the texture is a xpm file
**		- Return true if the texture is valid
*/

int	ft_check_xpm(t_map *map)
{
	if (map->no && ft_strncmp(&map->no[ft_strlen(map->no) - 4], ".xpm", 4) != 0)
		return (printf("Error\nNO texture is not a xpm file\n"), 1);
	if (map->so && ft_strncmp(&map->so[ft_strlen(map->so) - 4], ".xpm", 4) != 0)
		return (printf("Error\nSO texture is not a xpm file\n"), 1);
	if (map->we && ft_strncmp(&map->we[ft_strlen(map->we) - 4], ".xpm", 4) != 0)
		return (printf("Error\nWE texture is not a xpm file\n"), 1);
	if (map->ea && ft_strncmp(&map->ea[ft_strlen(map->ea) - 4], ".xpm", 4) != 0)
		return (printf("Error\nEA texture is not a xpm file\n"), 1);
	return (0);
}
