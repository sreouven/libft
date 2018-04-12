/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreouven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:27:08 by sreouven          #+#    #+#             */
/*   Updated: 2018/03/19 14:56:57 by sreouven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <inttypes.h>
# include "libft.h"

# define MD_H	(1 << 2)
# define MD_HH	(1 << 3)
# define MD_L	(1 << 4)
# define MD_LL	(1 << 5)
# define MD_J	(1 << 6)
# define MD_Z	(1 << 7)

typedef struct	s_frmt
{
	int			prec;
	char		type;
	int			size;
	int			fg_minus;
	int			fg_hashtag;
	int			fg_zero;
	int			fg_plus;
	int			fg_space;
	int			md;
	int			padd;
	int			neg;
}				t_frmt;

int				is_in(char *s, char c);
int				ft_printf(const char *restrict format, ...);
int				analyse(va_list *args, const char *format);
void			init_format(t_frmt *ptr);
int				parser(va_list *ap, char **str);
void			pars_padd_prec(char **str, t_frmt *ptr);
void			pars_flag(char **str, t_frmt *ptr);
void			pars_modifier(char **str, t_frmt *ptr);
void			pars_type(char **str, t_frmt *ptr);
int				print_args(t_frmt *ptr, va_list *ap);
char			*precision(char *str, t_frmt *ptr);
char			*precision_o(char *str, t_frmt *ptr);
char			*precision_x(char *str, t_frmt *ptr);
int				return_precision(t_frmt *ptr, char *str);
int				print_s(t_frmt *ptr, va_list *ap);
int				print_str(t_frmt *ptr, char *str);
int				print_c(t_frmt *ptr, va_list *ap);
int				print_di(t_frmt *ptr, va_list *ap);
int				print_xxou(t_frmt *ptr, va_list *ap);
int				print_dou(t_frmt *ptr, va_list *ap);
int				ft_print_nchar(char c, int n);
int				ajust_size(int len, t_frmt *ptr, char *str);
int				prefix(char *str, t_frmt *ptr);
int				padding(size_t len, t_frmt *ptr, char *str);
int				print_ptr(t_frmt *ptr, va_list *ap);
int				ft_putwc(wchar_t c);
int				ft_wclen(wchar_t c);
int				ft_wcslen(wchar_t *s);
int				print_big_c(t_frmt *ptr, va_list *ap);
int				print_big_s(t_frmt *ptr, va_list *ap);
char			*ft_wctostr(wchar_t c);
char			*ft_ctos(int c);

#endif
