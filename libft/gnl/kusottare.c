/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kusottare.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:36:48 by khorike           #+#    #+#             */
/*   Updated: 2023/06/29 12:53:16 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*kusottare(char **one_fd_line)
{
	if (*one_fd_line)
	{
		free(*one_fd_line);
		*one_fd_line = NULL;
	}
	return (NULL);
}
