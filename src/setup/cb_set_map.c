/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:44:45 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:19:01 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_setmap(int fd)
**		- Set the map
**		- Return the map
*/

char	**ft_setmap(int fd)
{
	char	**map;

	map = ft_set(fd);
	if (map == NULL)
		return (NULL);
	if (ft_len_tab(map) == 0)
		return (free_tab(map), printf("Error\nMap Not found\n"), NULL);
	if (ft_check_pos(map) == false)
		return (free_tab(map), NULL);
	return (map);
}

/*	ft_set(int fd)
**		- Set the map
**		- Return the map
*/

char	**ft_set(int fd)
{
	char	*line;
	char	*buffer;
	char	**map;
	int		i;

	i = 0;
	buffer = ft_strdup("");
	line = get_next_line(fd);
	line = ft_check_nl(line, fd);
	while (line != NULL)
	{
		if (i == 0)
			buffer = ft_strjoin_free(buffer, line);
		if (buffer == NULL || line[0] == '\n')
			i = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (i == 1)
		return (free(buffer), printf("Error\nNew line on map\n"), NULL);
	map = ft_split(buffer, '\n');
	if (map == NULL)
		return (free(buffer), NULL);
	return (free(buffer), map);
}
