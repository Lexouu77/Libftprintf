/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:06 by ahamouda          #+#    #+#             */
/*   Updated: 2017/02/14 04:57:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"
# include "ft_printf_struct.h"

# define PRINTF_BUFF_SIZE 256

# define IS_APLHAC(c) ((c) == 'c' || (c) == 'C' || (c) == 's' || (c) == 'S')
# define IS_APLHAT(c) (IS_APLHAC(c) || (c) == '%')

# define IS_SPEC(c) ((c) == 'V' || (c) == 'v' || (c) == 'B')
# define IS_SPET(c) ((c) == 'n' || (c) == 'p' || (c) == 'b' || IS_SPEC(c))

# define IS_NUMA(c) ((c) == 'd' || (c) == 'D' || (c) == 'i' || (c) == 'u')
# define IS_NUMB(c) ((c) == 'U' || (c) == 'x' || (c) == 'X' || (c) == 'O')
# define IS_NUMT(c) (IS_NUMA(c) || IS_NUMB(c) || (c) == 'o')

# define IS_VALIDT(c) (IS_APLHAT(c) || IS_SPET(c) || IS_NUMT(c))

# define IS_SUBSPEA(c) ((c) == 'h' || (c) == 'l' || (c) == 'j' || (c) == 'z')
# define IS_SUBSPEB(c) ((c) == 'L' || (c) == 't')
# define IS_SUBSPE(c) (IS_SUBSPEA(c) || IS_SUBSPEB(c))

# define IS_VALIDC(c) (IS_VALIDT(c) || FT_ISDIGIT(c) || IS_SUBSPE(c))

# define CTB(x) copy_char_to_buffer(x)
# define STB(x, y) copy_str_to_buffer(x, y)

extern size_t	g_len;
extern size_t	g_m_len;
extern char		*g_buffer;

void		copy_char_to_buffer(char c);
char		*copy_str_to_buffer(char *s, size_t len);
void		display_alpha_var(t_printf_flag *flag, va_list *va);
void		display_numeric_var(t_printf_flag *flag, va_list *va);
void		display_spe_var(t_printf_flag *flag, va_list *va);
int			ft_printf(char *format, ...);
int			ft_printf_hidden(char *format, ...);
int			ft_printf_buffed(int fd, int flush, char *format, va_list vb);
char		*get_dot_star(t_printf_flag *flag, char *str, va_list *va);
char		*get_min_area_size(t_printf_flag *flag, char *str);
char		*get_operator(t_printf_flag *flag, char *str);
char		*get_precision(t_printf_flag *flag, char *str);
char		*get_star(t_printf_flag *flag, char *str, va_list *va);
char		*get_sub_specifier(t_printf_flag *flag, char *str);
char		*get_zero_or_space_or_hash(t_printf_flag *flag, char *str);
void		loop_on_str(char *str, va_list *va);
void		malloc_buffer(size_t len);
void		print_char(t_printf_flag *flag);
void		print_normal_char(va_list *va, t_printf_flag *flag);
void		print_normal_string(va_list *va, t_printf_flag *flag);
void		resize_buffer(size_t len);

#endif
