/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:02:31 by khorike           #+#    #+#             */
/*   Updated: 2023/06/24 14:55:09 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_kai(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr_kai(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_bzero_kai(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc_kai(size_t number, size_t size)
{
	void	*ptr;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	if (number > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(number * size);
	if (!ptr)
		return (NULL);
	ft_bzero_kai(ptr, number * size);
	return (ptr);
}

char	*ft_strjoin_kai(const char *s1, const char *s2)
{
	char	*p;
	size_t	i;

	if (!s2)
		return (NULL);
	if (!s1)
		p = (char *)ft_calloc_kai((ft_strlen_kai(s2) + 1), sizeof(char));
	else
		p = (char *)ft_calloc_kai(ft_strlen_kai(s1)
				+ ft_strlen_kai(s2) + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	return (p);
}
