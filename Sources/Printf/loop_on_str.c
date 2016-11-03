/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_on_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:00:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/11/03 19:06:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_check_flags(char *str, va_list *va, t_printf_flag *flag)
{
	while (is_a_good_flag_or_type(str) && !flag->type) // change it later
	{
		if (is_a_valid_type(*str)) // same ^
			flag->type = *str++;
		else if (IS_SUBSPE(*str))
			str = get_sub_specifier(flag, str); // OK
		else if (*str == 48 || *str == 32 || *str == 35)
			str = get_zero_or_space_or_hash(flag, str);
		else if (*str == 45 || *str == 43)
			str = get_operator(flag, str);
		else if (*str == 46 && *(str + 1) == 42)
			str = get_dot_star(flag, str, va);
		else if (*str == 42)
			str = get_star(flag, str, va);
		else if (*str == 46)
			str = get_precision(flag, ++str);
		else if (FT_ISDIGIT(*str))
			str = get_min_area_size(flag, str);
		else if (*str == 91 && str[1] == 91)
			str = get_ansi_code(flag, ++str, list);
	}
	if (*str)
		flag->type = (flag->type) ? flag->type : *str++;
	return (str);
}

static char	*copy_var_to_buffer(char *s, va_list *va)
{
	t_printf_flag	flag;

	flag = ft_bzero(&flag, sizeof(t_printf_flag));
	str = ft_printf_check_flags(&flag, str, va, list);
	if (flag->type)
		display_final(&flag, va, list);
	return (str);
}

static char	*copy_str_to_buffer(char *s, size_t len) // a metttre en fonction dans un autre fichier.
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
		g_len++;
		i++;
	}
	return (s + i);
}

void		loop_on_str(char *str, va_list *va)
{
	while (*str)
	{
		if (*str == '%')
			str = copy_var_to_buffer(++str, va);
		else
			str = copy_str_to_buffer(str, ft_strxlen(str, '%'));
	}
}
