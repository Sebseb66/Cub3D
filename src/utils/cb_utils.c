/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:20:51 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/07 22:56:45 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*ptr;
	size_t			protect;

	protect = nitems * size;
	if ((size != 0) && (protect / size != nitems))
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

char	*ft_strdup(const char *str1)
{
	char	*dup;
	int		i;

	i = 0;
	while (str1[i] != '\0')
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		dup[i] = str1[i];
		i++;
	}
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && i < n - 1 && n != 0)
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		s_len;
	char				*sub_str;

	s_len = ft_strlen((char *)s);
	if (start > s_len)
	{
		len = 0;
		start = s_len;
	}
	if (len > s_len)
		len = s_len;
	if (start + len > s_len)
		len = s_len - start;
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
