/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:25:04 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:05:39 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_get_map(t_map *map)
**		- Get the map and verify if it's valid
**		- Return 1 if the map is not valid
*/

int	ft_get_map(t_map *map)
{
	char	*line;
	char	*tmp;

	tmp = get_next_line(map->fd);
	if (tmp == NULL)
		return (printf("Error\ncouldn't read from file\n"), 1);
	line = ft_strtrim(tmp, " \t");
	free(tmp);
	while (line != NULL)
	{
		if (ft_check_map(map, line) == 1)
			return (get_next_line(-100), free(line), 1);
		free(line);
		if (map->ea && map->no
			&& map->so && map->we
			&& ft_check_floor(map) == 0)
			break ;
		tmp = get_next_line(map->fd);
		if (tmp == NULL)
			return (printf("Error\n file end reached in parsing\n"), 1);
		line = ft_strtrim(tmp, " \t");
		free(tmp);
	}
	return (0);
}

/*	ft_check_map(t_map *map, char *line)
**		- Check if the all the components of the map are valid
**		- Return 1 if the map is not valid
*/

int	ft_check_map(t_map *map, char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (line[0] == '\n')
		i = 1;
	if (i == 0 && ft_check_cor(line, 1) == true)
	{
		if (ft_get_texture(map, line, j) == 1)
			return (1);
	}
	else if (i == 0 && ft_check_cor(line, 2) == true)
	{
		if (ft_check_rgb(map, line) == 1)
			return (1);
	}
	else
		if (i == 0)
			return (printf("Error\n.cub is not valid\n"), 1);
	return (0);
}

/*	ft_check_cor(char *line, int check)
**		- Check if the line is a texture or a color
**		- Return true if the line is a texture or a color
*/

bool	ft_check_cor(char *line, int check)
{
	if (check == 1 && (ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "NO	", 3) == 0
			|| ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "SO	", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "WE	", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "EA	", 3) == 0))
		return (true);
	else if (check == 2 && (ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0
			|| ft_strncmp(line, "F	", 2) == 0
			|| ft_strncmp(line, "C	", 2) == 0))
		return (true);
	return (false);
}

/*	ft_check_nl(char *line, int map_fd)
**		- Check if the line is a new line
**		- Return the next line
*/

char	*ft_check_nl(char *line, int map_fd)
{
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(map_fd);
	}
	return (line);
}
