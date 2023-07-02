/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:31:57 by khorike           #+#    #+#             */
/*   Updated: 2023/06/25 11:57:40 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

ssize_t			ft_putchar(char c);
ssize_t			ft_putstr(char *s);
ssize_t			ft_putnbr(int n);
ssize_t			ft_put_unsigned_nbr(unsigned int n);
ssize_t			ft_putnbr_base(long int n, int low_or_up);
ssize_t			ft_put_pointer(unsigned long long n);
size_t			ft_strlen_pri(const char *s);

int				ft_printf(const char *format, ...);

#endif
