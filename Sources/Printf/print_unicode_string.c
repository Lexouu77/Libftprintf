/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:38 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 08:43:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		get_nb_max_char_unicode_s(t_printf_flag *flag, int *x)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!flag->is_precision_here)
		return (-1);
	while (x[i] && len < flag->nb_max_char)
	{
		if (len + get_unicode_len(x[i]) <= flag->nb_max_char)
			len += get_unicode_len(x[i]);
		else
		{
			flag->is_precision_here = 0;
			flag->nb_max_char = 0;
			return (len);
		}
		++i;
	}
	flag->nb_max_char -= len;
	return (len);
}

static	int		get_u_len(int *x)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (x[++i])
		len += get_unicode_len(*x);
	return (len);
}

static	void	add_u_string(t_printf_flag *flag, int *c, int len)
{
	int	i;

	i = 0;
	while (!flag->minus && flag->is_min_area_size_here &&
			++flag->i < flag->nb_min_char)
		flag->zero ? CTB(48) : CTB(32);
	flag->i = -1;
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		CTB(32);
	while (((c[i] && !flag->is_precision_here) ||
			(flag->is_precision_here && 0 < flag->nb_max_char + len)) && len)
	{
		len -= get_unicode_len(c[i]);
		copy_unicode_char_to_buffer(c[i]);
		++i;
	}
	flag->i = -1;
	while (flag->minus && flag->is_min_area_size_here &&
			++flag->i < flag->nb_min_char)
		flag->zero ? CTB(48) : CTB(32);
}

void			print_unicode_string(va_list *va, t_printf_flag *flag)
{
	void	*x;
	int		len;

	flag->i = -1;
	x = va_arg(*va, void*);
	if (x == NULL)
		STB("(null)", 6);
	else
	{
		len = get_nb_max_char_unicode_s(flag, (int*)x);
		if (len == -1)
			len = get_u_len((int*)x);
		flag->nb_min_char -= len;
		add_u_string(flag, (int*)x, len);
	}
}
