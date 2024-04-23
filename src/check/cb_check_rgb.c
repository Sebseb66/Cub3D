/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:35:35 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:03:44 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_check_rgb(t_map *map, char *line)
**		- Check if the RGB is valid
**		- Split the RGB and check if the values are valid
**		- Return true if the RGB is valid
*/

int	ft_check_rgb(t_map *map, char *line)
{
	char	**rgb;
	char	*trim;
	int		i;
	int		j;

	i = 1;
	trim = ft_trim_space(line);
	if (!trim)
		return (1);
	rgb = ft_split(trim + 1, ',');
	if (!rgb)
		return (free(trim), 1);
	if (ft_len_tab(rgb) != 3)
		return (free_tab(rgb), free(trim),
			printf("Error\nWrong RGB format\n"), 1);
	i = -1;
	while (rgb[++i])
	{
		j = -1;
		if (ft_check_rgb_range(rgb, trim, i, j) == 1)
			return (1);
	}
	if (ft_get_rgb(map, trim, rgb) == 1)
		return (free_tab(rgb), free(trim), 1);
	return (free_tab(rgb), free(trim), 0);
}

/*	ft_check_rgb_range(char **rgb, char *line, int i, int j)
**		- Check if the RGB values are valid
**		- Return true if the RGB is valid
*/

int	ft_check_rgb_range(char **rgb, char *line, int i, int j)
{
	while (rgb[i][++j])
		if (ft_isdigit(rgb[i][j]) == 0 && rgb[i][j] != '\n')
			return (free_tab(rgb), free(line),
				printf("Error\nRGB is not valid\n"), 1);
	return (0);
}

/*	ft_get_rgb(t_map *map, char *id, char **rgb)
**		- Get the RGB values and check if they are valid
**		- Return true if the RGB is valid
*/

int	ft_get_rgb(t_map *map, char *id, char **rgb)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) >= 0 && ft_atoi(rgb[i]) <= 255)
		{
			if ((id[0] == 'F' && map->floor[j] != -1)
				|| (id[0] == 'C' && map->ceiling[k] != -1))
				return (printf("Error\nRGB is duplicate\n"), 1);
			if (id[0] == 'F' && map->floor[j] == -1)
				map->floor[j++] = ft_atoi(rgb[i]);
			else if (id[0] == 'C' && map->ceiling[k] == -1)
				map->ceiling[k++] = ft_atoi(rgb[i]);
		}
		else
			return (printf("Error\nRGB out of range\n"), 1);
		i++;
	}
	return (0);
}

/*	ft_check_floor(t_map *map)
**		- Check if rgb of floor and ceiling are valid
**		- Return true if the rgb is valid
*/

int	ft_check_floor(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->floor[i] == -1 || map->ceiling[i] == -1)
			return (1);
		i++;
	}
	return (0);
}
