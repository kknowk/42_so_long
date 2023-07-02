/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:53:12 by khorike           #+#    #+#             */
/*   Updated: 2023/05/17 12:00:02 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen && s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dnl;
	size_t	src_len;

	src_len = ft_strlen(src);
	dnl = ft_strnlen(dest, size);
	if (dnl == size)
		return (dnl + src_len);
	if (src_len < size - dnl)
		ft_memcpy(dest + dnl, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dnl, src, size - dnl - 1);
		dest[size - 1] = '\0';
	}
	return (dnl + src_len);
}
