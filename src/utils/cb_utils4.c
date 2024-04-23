/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:47:10 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 23:01:58 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strjoin_free(const char *s1, const char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str_j;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str_j = ft_calloc(len + 1, sizeof(char));
	if (str_j == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str_j[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str_j[i + j] = s2[j];
		j++;
	}
	free((void *) s1);
	return (str_j);
}

bool	ft_is_letters(char c)
{
	if (ft_strchr("01NSWE", c))
		return (true);
	return (false);
}

void	ft_bzero(void *dst, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned int	i;

	ptr_dst = (unsigned char *) dst;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = '\0';
		i++;
	}
}
