/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:01:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/11/03 18:51:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf.h"
# include "ft_printf_struct.h"

# define PRINTF_BUFF_SIZE 256

# define IS_APLHAC(c) ((c) == 'c' || (c) == 'C' || (c) == 's' || (c) == 'S')
# define IS_APLHAT(c) (IS_APLHAC(c) || (c) == '%')

# define IS_SPET(c) ((c) == 'n' || (c) == 'p')

# define IS_NUMA(c) ((c) == 'd' || (c) == 'D' || (c) == 'i' || (c) == 'u')
# define IS_NUMB(c) ((c) == 'U' || (c) == 'x' || (c) == 'X' || (c) == 'O')
# define IS_NUMT(c) (IS_NUMA(c) || IS_NUMB(c) || (c) == 'o')

# define IS_VALIDT(c) (IS_APLHAT(c) || IS_SPET(c) || IS_NUMT(c))

# define IS_SUBSPEA(c) ((c) == 'h' || (c) == 'l' || (c) == 'j' || (c) == 'z')
# define IS_SUBSPEB(c) ((c) == 'L' || (c) == 't')
# define IS_SUBSPE(c) (IS_SUBSPEA(c) || IS_SUBSPEB(c))

# define IS_VALIDC(c) (IS_VALIDT(c) || FT_ISDIGIT(c) ||)

extern size_t	g_len;
extern size_t	g_m_len;
extern char		*g_buffer;

size_t	g_len = 0;
size_t	g_m_len = 0;
char	*g_buffer = NULL;

int			ft_printf(char *format, ...);
int			ft_printf_buffed(int fd, int flush, char *format, va_list vb);
char		*get_sub_specifier(t_printf_flag *flag, char *str);
void		loop_on_str(char *str, va_list *va);
void		malloc_buffer(size_t len);
void		resize_buffer(size_t len);


#endif
