/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:21:00 by ahamouda          #+#    #+#             */
/*   Updated: 2017/11/28 18:03:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		resize_buffer(size_t len)
{
	char	*str;
	size_t	m_len;

	m_len = g_ftprintf_m_len;
	while (m_len < len + g_ftprintf_m_len)
		m_len += PRINTF_BUFF_SIZE;
	g_ftprintf_m_len = m_len;
	if (!(str = malloc(sizeof(char) * m_len)))
		MALLOC_ERROR;
	ft_memcpy(str, g_ftprintf_buffer, g_ftprintf_len);
	free(g_ftprintf_buffer);
	g_ftprintf_buffer = str;
}
