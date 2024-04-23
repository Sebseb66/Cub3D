/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:19:04 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:20:58 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	ft_check_extension(char *str)
**		- Check if the file has the right extension
**		- Return 1 if the file has the right extension
*/

int	ft_check_extension(char *str)
{
	int		i;
	char	**path;
	char	**file;

	i = 0;
	path = ft_split(str, '/');
	while (path[i] != NULL)
		i++;
	i--;
	file = ft_split(path[i], '.');
	free_tab(path);
	i = 0;
	while (file[i] != NULL)
		i++;
	i--;
	if (ft_strncmp(file[i], "cub", 3) != 0)
		return (free_tab(file), 0);
	free_tab(file);
	return (1);
}
