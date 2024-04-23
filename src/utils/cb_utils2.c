/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:28:39 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/30 00:00:27 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size != 0)
	{
		while (src[j] != '\0' && j < size - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str);
	while (i < len)
	{
		if (str[i] == (char)c)
			return ((char *) str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *) str + i);
	return (0);
}

static int	check_front(const char *s, const char *set)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	check_back(const char *s, const char *set)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s) - 1;
	while (len >= 0)
	{
		if (ft_strchr(set, s[len]) == 0)
			break ;
		i++;
		len--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	back;

	start = check_front(s1, set);
	back = check_back(s1, set);
	if (start == ft_strlen((char *)s1))
		return (ft_strdup(""));
	return (ft_substr(s1, start, ft_strlen((char *)s1) - back - start));
}
