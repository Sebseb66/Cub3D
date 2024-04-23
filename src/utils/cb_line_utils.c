/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:36:43 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:22:30 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_trim_space(char *line)
**		- Trim the space in the line
*/

char	*ft_trim_space(char *line)
{
	char	*trim;
	int		i;
	int		j;
	int		count;

	i = -1;
	j = 0;
	count = 0;
	while (line[++i])
		if (ft_isspace(line[i]) == false)
			count++;
	trim = ft_calloc(count + 1, sizeof(char));
	if (!trim)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		if (ft_isspace(line[i]) == false)
			trim[j++] = line[i];
	}
	return (trim);
}

/*	ft_init_null(t_map *map)
**		- Initialize the struct to NULL
*/

void	ft_init_null(t_map *map)
{
	int	i;

	i = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	while (++i < 3)
	{
		map->floor[i] = -1;
		map->ceiling[i] = -1;
	}
}

/*	ft_malloc_img(t_textures *tex)
**		- Malloc the img struct
*/

void	ft_malloc_img(t_textures *tex)
{
	tex->background = malloc(sizeof(t_img));
	tex->wall_ea = malloc(sizeof(t_img));
	tex->wall_no = malloc(sizeof(t_img));
	tex->wall_we = malloc(sizeof(t_img));
	tex->wall_so = malloc(sizeof(t_img));
}
