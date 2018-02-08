/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:34:58 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/12/21 13:34:59 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

# define ON	 1
# define OFF 0


# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <locale.h>

#define mask3 4034953344

typedef struct 		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				cell;
	int				zero;
}					t_flags;

typedef struct		s_width
{
    int 			number;
	int				star;
}					t_width;

typedef struct			s_precision
{
	int                 dot_number;
	int 				fl;
    int                 yes;
	int					dot_star;
}						t_precision;

typedef struct			s_length
{
	int					l;
	int					L;
	int					hh;
	int					h;
	int					ll;
	int					j;
	int					z;
}						t_length;

typedef struct			s_specifier
{
	int					s;
	int					S;
	int					p;
	int					d;
	int					D;
	int					i;
	int					o;
	int					O;
	int					u;
	int					U;
	int					x;
	int					X;
	int					c;
	int					C;
	int					proc;
}						t_specifier;

typedef struct			s_lst
{
	t_flags			*flags;
	t_width			*width;
	t_precision		*precision;
	t_length		*length;
	t_specifier		*specifier;
	char			*text;
	char 			*wrong;
}						t_lst;


const char	*ft_get_flags(const char *form, t_flags *run);
const char	*ft_get_width(const char *form, t_width *run, va_list args, t_flags *f);
const char	*ft_get_precision(const char *form, t_precision *run, va_list args);
const char	*ft_get_length(const char *form, t_length *run);
int			ft_get_specifier(const char *form, t_specifier *run);
t_flags		*zero_to_flags(t_flags *run);
t_width		*zero_to_width(t_width *run);
t_precision	*zero_to_precision(t_precision *run);
t_length	*zero_to_length(t_length *run);
t_specifier	*zero_to_specifier(t_specifier *run);


char		*ft_itoa_base(size_t num, int base, t_specifier *spec);
char		*ft_itoa_base_pt(ssize_t n);
char		*ft_realloc_cat(char *array, char *source);
const char	*ft_wrong(const char *form, t_lst *run);

int			ft_printf(const char *format, ...);
void		*ft_realloc(void *array, size_t size);
int			search_base(t_specifier *spec);
int     	unic_sn(wchar_t *array, int num);
int     	unic_s(wchar_t *array);
int			unic_c(wchar_t ar);
int     	length_s(wchar_t *ar);
int     	length_c(wchar_t ar);
int     	length_s_one(wchar_t *ar);
int     	ulen_lim(int num, wchar_t *ar);
int     	ft_len(char *s);
#endif