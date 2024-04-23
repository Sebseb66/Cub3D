/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:48:52 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:02:28 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_check_lines(char **map)
**		- Check all the side of the map
**		- Return true if the map is valid
*/

bool	ft_check_lines(char **map)
{
	if (ft_check_side(map, 0) == false)
		return (printf("Error\nThe first line is NULL\n"), false);
	if (ft_check_side(map, ft_len_tab(map) - 1) == false)
		return (printf("Error\nThe last line is NULL\n"), false);
	if (ft_check_middle(map) == false)
		return (printf("Error\nOne of middle line is NULL\n"), false);
	if (ft_check_border(map) == false)
		return (printf("Error\nThe map is not surrounded by walls\n"), false);
	if (ft_check_current(map) == false
		|| ft_check_next(map) == false)
		return (printf("Error\nThe map is not surrounded by walls\n"), false);
	return (true);
}

/*	ft_check_pos(char **map)
**		- Check if the components of the map are valid
**		- Return true if the map is valid
*/

bool	ft_check_pos(char **map)
{
	if (ft_check_lines(map) == false)
		return (false);
	if (!ft_check_letters(map))
		return (printf("Invalid map component/letters found\n"), false);
	if (ft_player_pos(map) == 'F')
		return (printf("Invalid player position\n"), false);
	return (true);
}

/*	ft_check_letters(char **map)
**		- Check if the map contains only valid letters
**		- Return true if the map is valid
*/

bool	ft_check_letters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_is_letters(map[i][j]) && !ft_isspace(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*	ft_player_pos(char **map)
**		- Check if the player position is valid
**		- Return the player position
*/

char	ft_player_pos(char **map)
{
	if (ft_check_points('N', map) == 1 && ft_check_points('S', map) == 0
		&&ft_check_points('E', map) == 0 && ft_check_points('W', map) == 0)
		return ('N');
	else if (ft_check_points('S', map) == 1 && ft_check_points('N', map) == 0
		&&ft_check_points('E', map) == 0 && ft_check_points('W', map) == 0)
		return ('S');
	else if (ft_check_points('E', map) == 1 && ft_check_points('S', map) == 0
		&&ft_check_points('N', map) == 0 && ft_check_points('W', map) == 0)
		return ('E');
	else if (ft_check_points('W', map) == 1 && ft_check_points('S', map) == 0
		&&ft_check_points('E', map) == 0 && ft_check_points('N', map) == 0)
		return ('W');
	return ('F');
}

/*	ft_check_points(char c, char **map)
**		- Check if the map contains only one player position
**		- Return the number of player position
*/

int	ft_check_points(char c, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
