/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:26:07 by khorike           #+#    #+#             */
/*   Updated: 2023/05/19 14:16:06 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atat(const char *nptr, int count)
{
	size_t	i;
	size_t	j;
	size_t	digit;

	i = 0;
	j = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		j = j * 10 + digit;
		if (count == 1)
		{
			if ((j == LONG_MAX / 10 && nptr[i + 1] - '0' > LONG_MAX % 10)
				|| (j > LONG_MAX / 10 && nptr[i + 1]))
				return ((int)(LONG_MAX));
		}
		else
		{
			if ((j == LONG_MAX / 10 && nptr[i + 1] - '0' > LONG_MAX % 10 + 1)
				|| (j > LONG_MAX / 10 && nptr[i + 1]))
				return ((int)(LONG_MIN));
		}
		i++;
	}
	return ((int)(j * count));
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 1;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			count *= -1;
		return (atat(nptr + i + 1, count));
	}
	return (atat(nptr + i, count));
}
