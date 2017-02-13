/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:49 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/13 18:38:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H
/*
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
*/

typedef struct		s_printf_flag
{
	char			precision[10];
	char			min_area_size[10];
	int				nb_max_char;
	int				hash;
	int				i;
	int				nb_c_written;
	int				nb_min_char;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	char			type;
	char			sign;
	char			is_min_area_size_here;
	char			is_precision_here;
	char			sub_specifier[2];
//	t_fg_color		fg_color;
//	t_bg_color		bg_color;
//	t_special		special;
	char			reset_fg;
	char			reset_ansi;
	char			reset_bg;
	char			star;
	char			dot_star;
	char			padding_byte;
	int				padding_bytes;
	char			*converted_number;
	char			*tmp_conv_nb;
}					t_printf_flag;



#endif
