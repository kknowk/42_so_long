/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:04:08 by khorike           #+#    #+#             */
/*   Updated: 2023/06/30 13:10:54 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_without_newline(char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = NULL;
	if (!str)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(str)));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	if (ft_strchr(s, '\n') && i != 0)
		s[i - 1] = '\0';
	else
		s[i] = '\0';
	return (s);
}

char	*ft_strjoin_without_newline(char *s1, char *s2, t_game *game)
{
	char	*p;
	size_t	i;
	char	*tmp1;

	tmp1 = s1;
	if (!s2)
		return (NULL);
	if (!s1)
		p = (char *)ft_calloc((ft_strlen(s2) + 1), sizeof(char));
	else
		p = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	if (ft_strchr(p, '\n') && i != 0)
	{
		game->kaigyou_count++;
		p[i - 1] = '\0';
	}
	return (p);
}

char	*ft_temp_sj(t_game *game, char *line, int fd)
{
	char	*tmp;

	(void)fd;
	tmp = ft_strjoin_without_newline(game->str_line, line, game);
	if (game->str_line)
		free (game->str_line);
	if (!tmp)
	{
		if (line)
			free(line);
		game->error = 1;
		return (NULL);
	}
	return (tmp);
}

int	ft_count_letter(char *str, char target)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == target)
			count++;
		str++;
	}
	return (count);
}
