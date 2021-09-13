/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linguyen <linguyen@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:36:28 by linguyen          #+#    #+#             */
/*   Updated: 2021/09/05 14:45:42 by linguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"
# define NULLSTR "(null)"

int	g_count;

/*
** Printf() format: %[flags][width][.precision]type
** 
** Flags explanation
** dot: to know if there is precision
** precision (dot): initialised as -1 (means that precision is omitted)
** zero precision and negative precision is different
** star: (*) read variable argument/if precision is a variable argument
*/

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		star;
	int		neg_num;
	char	type;
}	t_flag;

/* helper - conversion_handle.c */
int			digit_length(int n);
int			is_conversion(char c);

/* padding_handle.c */
char		*left_blank_padding(t_flag flag, int len, char *str);
char		*left_zero_padding(char *str, int len);
char		*right_blank_padding(t_flag flag, int len, char *str);

/* struct_handle.c */

const char	*width_handle(t_flag *flag, const char *start, va_list ap);
const char	*precision_handle(t_flag *flag, const char *start, va_list ap);
int			type_decision(t_flag flag, va_list ap);
const char	*ft_format(const char *start, va_list ap);

/* char_handle.c */
char		*char_blank_padding(t_flag flag, int len, char c);
int			char_handle(t_flag flag, va_list ap);

/* print_str.c */
void		print_str(t_flag flag, char *str, int len);

/* percent_handle */
char		*percent_padding(t_flag flag, int len);
int			percent_handle(t_flag flag);

/* str_padding_handle.c */
char		*left_blank_str(t_flag flag, char *str, int len);
char		*right_blank_str(t_flag flag, char *str, int len);

/* pointer_handle.c */
char		*hex_conversion(t_flag flag, char *str, unsigned long long num);
char		*ptr_blank_padding(t_flag flag, int len, char *str);
int			ptr_handle(t_flag flag, va_list ap);

/* num_padding_handle.c */
void		len_decision(t_flag *flag, int *total, int *len);
char		*left_blank_num(t_flag *flag, int len, char *str);
char		*right_blank_num(t_flag flag, int len, char *str);
char		*left_zero_num(t_flag flag, int len, char *str);

/* num_handle.c */
char		*itoa_base(t_flag *flag, long long num, int base, char *result);
char		*num_paddling_handle(t_flag flag, char *str);
int			num_handle(t_flag flag, va_list ap);

/* str_handle.c */
char		*ft_strncpy(char *dst, char *src, int len);
char		*str_padding_handle(t_flag *flag, va_list ap);
int			str_handle(t_flag flag, va_list ap);

/* ft_printf.c */
void		flag_init(t_flag *flag);
int			ft_printf(const char *format, ...);
#endif
