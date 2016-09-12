/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 15:40:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	get_base_char(int c, char type)
{
	if (c >= 10 && c <= 15)
		return (type < 96) ? (65 + (c - 10)) : (97 + (c - 10));
	return (48 + c);
}

char		*itoa_base(void *x, int base, char type)
{
	char					*str;
	int						size;
	unsigned long long		nb;

	nb = (unsigned long long)x;
	size = 1;
	while (nb /= base)
		++size;
	str = ft_strnew(size);
	nb = (unsigned long long)x;
	while (--size >= 0)
	{
		str[size] = get_base_char((nb % base), type);
		nb /= base;
	}
	return (str);
}
