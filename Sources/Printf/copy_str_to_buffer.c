/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_to_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 04:12:24 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 05:24:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*copy_str_to_buffer(char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (!g_buffer)
		malloc_buffer(len);
	if (g_len + len < g_m_len)
		resize_buffer(len);
	while (i < len)
	{
		g_buffer[g_len + i] = s[i];
		i++;
	}
	g_len += i;
	return (s + i);
}

void		copy_char_to_buffer(char c)
{
	if (!g_buffer)
		malloc_buffer(1);
	if (g_len + 1 < g_m_len)
		resize_buffer(1);
	g_buffer[g_len++] = c;
}

void		copy_unicode_char_to_buffer(int c)
{
	 //uc_to_str ??
}
