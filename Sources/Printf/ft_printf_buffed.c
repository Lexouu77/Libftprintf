/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 05:55:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/16 14:42:26 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	instant_flush(int fd)
{
	size_t		i;

	if (!g_len)
		return (0);
	i = g_len;
	write(fd, g_buffer, g_len);
	g_len = 0;
	g_m_len = 0;
	free(g_buffer);
	g_buffer = NULL;
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
//	TODO : Faire une structure un peu plus decente. et malloc de PRINTF_BUFF_SIZE
// si c'est trop petit, Faire un while pour calculer combien de plus il faut malloc, et ensuite save l'old size et faire un malloc avec la newsize puis copier l'ancienne size. et commencer a ecrire a partir de oldsize

