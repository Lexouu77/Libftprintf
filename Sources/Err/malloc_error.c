/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:50:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/11 18:57:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	malloc_error(const char *file, int line, const char *function)
{
	write(2, "Malloc Error in : ", 18);
	write(2, file, ft_strlen(file));
	write(2, " in : ", 6);
	write(2, function, ft_strlen(function));
	write(2, " at line : ", 11);
	line++;
//	putnbr_fd(2, line);
//	write(2, line, ft_strlen(line));
	write(2, "\n", 1);
	exit(-1);
}
