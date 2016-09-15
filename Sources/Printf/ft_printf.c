/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:05:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/15 19:10:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (ft_printf_buffed(1, 1, NULL, NULL));
	va_start(args, format);
	i = ft_printf_buffed(1, 1, format, args);
	va_end(args);
	return (i);
}
