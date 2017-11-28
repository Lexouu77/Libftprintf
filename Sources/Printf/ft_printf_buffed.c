/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:06:50 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/28 18:02:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	instant_flush(int fd)
{
	size_t		i;

	if (!g_ftprintf_len)
		return (0);
	i = g_ftprintf_len;
	write(fd, g_ftprintf_buffer, g_ftprintf_len);
	g_ftprintf_len = 0;
	g_ftprintf_m_len = 0;
	free(g_ftprintf_buffer);
	g_ftprintf_buffer = NULL;
	return ((int)i);
}

int			ft_printf_buffed(int fd, int flush, char *format, va_list vb)
{
	va_list		va;
	char		*format_cpy;

	if (!format && flush)
		return (instant_flush(fd));
	if (!format)
		return (0);
	format_cpy = ft_strdup(format);
	va_copy(va, vb);
	loop_on_str(format_cpy, &va);
	va_end(va);
	free(format_cpy);
	if (flush)
		return (instant_flush(fd));
	return (0);
}

int			ft_printf_hidden(char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (ft_printf_buffed(1, 0, NULL, NULL));
	va_start(args, format);
	i = ft_printf_buffed(1, 0, format, args);
	va_end(args);
	return (i);
}
