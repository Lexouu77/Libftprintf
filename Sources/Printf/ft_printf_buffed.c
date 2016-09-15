/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 05:55:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/15 19:10:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			instant_flush(int fd)
{
	int		i;

	if (!g_len)
		return (0);
	i = g_len;
	write(fd, g_buffer, g_len);
	g_len = 0;
	free(g_buffer);
	g_buffer = NULL;
	return (i);
}

char		*ft_printf_buffed(int fd, int flush, char *format, va_list vb)
{
	va_list		va;
	char		*format_cpy;
	int			i;
	t_info		*list;

	if (!format && flush)
		return (instant_flush(fd));

//	TODO : Faire une structure un peu plus decente. et malloc de PRINTF_BUFF_SIZE
// si c'est trop petit, Faire un while pour calculer combien de plus il faut malloc, et ensuite save l'old size et faire un malloc avec la newsize puis copier l'ancienne size. et commencer a ecrire a partir de oldsize
	format_cpy = ft_strdup(format);
	if (!(list = (t_info*)malloc(sizeof(t_info))))
		ft_malloc_error();
	va_copy(va, vb);
	list->nb_c_written = 0;
	list->nb_c_needed = 0;
	list->tmp = NULL;
	list->converted_string = NULL;
	i = display(format_cpy, &va, list);
	free(list);
	va_end(va);
	free(format_cpy);
	*len = i;
	return (list->converted_string);
}
