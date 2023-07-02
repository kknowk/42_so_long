/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:59:03 by khorike           #+#    #+#             */
/*   Updated: 2023/05/21 14:28:01 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	i;
	int	sign;

	i = 1;
	sign = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		sign *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (sign == -1)
		return (i + 1);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_count_digit(n);
	p = (char *)ft_calloc((len + 1), sizeof(char));
	if (!p)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(p, "-2147483648\0", 12));
	else if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	p[len] = '\0';
	while (len-- && p[len] != '-')
	{
		p[len] = '0' + n % 10;
		n /= 10;
	}
	return (p);
}
