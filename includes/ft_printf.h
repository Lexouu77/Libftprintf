/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/15 19:11:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"
# include "ft_printf_struct.h"

# define PRINTF_BUFF_SIZE 256

int			g_len;
char		*g_buffer;

extern int	g_len;
extern char	*g_buffer;

int			ft_printf(char *format, ...);
char		*ft_printf_buffed(int fd, int flush, char *format, va_list vb);


#endif
