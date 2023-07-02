/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:11 by khorike           #+#    #+#             */
/*   Updated: 2023/05/21 15:02:30 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + start, end - start + 1);
	p[end - start] = '\0';
	return (p);
}
