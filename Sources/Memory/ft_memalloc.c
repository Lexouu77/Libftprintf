/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/09 11:01:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		MALLOC_ERROR;
	ft_memset(mem, 0, size);
	return (mem);
}
