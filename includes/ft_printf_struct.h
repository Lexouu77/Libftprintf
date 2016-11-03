/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/11/03 20:03:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

typedef struct	s_printf_flag
{
	int			i;
	char		type;
	char		sign;
	char		sub_specifier[2];
	char		space;
	char		zero;
	char		minus;
	char		plus;
	char		hash;
	char		star;
	char		dot_star;
	char		is_precision_here;
	char		is_min_area_size_here;
	char		precision[10];
	char		min_area_size[10];
}				t_printf_flag;

#endif
