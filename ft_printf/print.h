/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:34:58 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 17:53:57 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <locale.h>

# define MASK3 4034953344

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				cell;
	int				zero;
}					t_flags;

typedef struct		s_width
{
	int				number;
}					t_width;

typedef struct		s_pr
{
	int				dot_number;
	int				fl;
	int				yes;
}					t_pr;

typedef struct		s_length
{
	int				l;
	int				cl;
	int				hh;
	int				h;
	int				ll;
	int				j;
	int				z;
}					t_length;

typedef struct		s_color
{
	int				re;
	int				gre;
	int				yel;
	int				blu;
	int				mag;
	int				cya;
	int				whi;
	int				rese;
}					t_color;

typedef struct		s_sp
{
	int				s;
	int				cs;
	int				p;
	int				d;
	int				cd;
	int				i;
	int				o;
	int				co;
	int				u;
	int				cu;
	int				x;
	int				cx;
	int				c;
	int				cc;
	int				b;
	int				proc;
}					t_sp;

typedef struct		s_lst
{
	t_flags			*flags;
	t_width			*width;
	t_pr			*pr;
	t_length		*length;
	t_sp			*sp;
	t_color			*color;
	char			*text;
	char			*wrong;
}					t_lst;

char				*ft_get_flags(char *form, t_flags *run);
char				*gt_wd(char *form, t_width *run, va_list args, t_flags *f);
char				*ft_get_precision(char *form, t_pr *run, va_list args);
char				*ft_get_length(char *form, t_length *run);
char				*get_color(char *form, t_color *run);
int					ft_get_specifier(char *form, t_sp *run);
t_flags				*zero_to_flags(t_flags *run);
t_pr				*zero_to_precision(t_pr *run);
t_length			*zero_to_length(t_length *run);
t_sp				*zero_to_specifier(t_sp *run);
t_color				*zero_to_color(t_color *run);
char				*ft_ib(size_t num, int base, t_sp *spec);
char				*ft_itoa_base_pt(ssize_t n);
char				*ft_realloc_cat(char *array, char *source);
char				*ft_wrong(char *form, t_lst *run);
int					ft_printf(const char *format, ...);
void				*ft_realloc(void *array, size_t size);
int					base(t_sp *spec);
int					unic_sn(wchar_t *array, int num);
int					unic_s(wchar_t *array);
int					unic_c(wchar_t ar);
int					length_s(wchar_t *ar);
int					length_c(wchar_t ar);
int					length_s_one(wchar_t *ar);
int					ulen_lim(int num, wchar_t *ar);
int					ft_len(char *s);
int					is_n(t_sp *spec, t_length *len);
int					type(t_lst *run);
int					ft_text(t_lst *run);
int					ft_numeric(t_lst *run);
int					ft_uni_type(t_sp *spec, t_length *len);
char				*num_di(va_list args, t_length *run, t_sp *spec);
char				*num_rest(va_list args, t_length *run, t_sp *spec);
char				*num_dou(va_list args, t_sp *spec, t_flags *flag);
char				*ft_format(char *form, t_lst *run, va_list args);
char				*parse_flags(intmax_t num, t_lst *run, char *res);
char				*parse_accuracy(t_lst *run, char *num);
char				*parse_wid(t_lst *run, char *num, char *accur, char *flag);
int					ft_text_m(char *fl_ac, char *width, char *num, t_lst *run);
int					ft_pt_zero(char *fl_wd, char *accur, char *num, t_lst *run);
int					pt_min_p(char *fl_ac, char *width, char *num, t_lst *run);
int					ft_puttext(char *wd_fl, char *accur, char *num, t_lst *run);
char				*pr_char(t_lst *run, char *num);
char				*ft_char_type(va_list args, t_sp *spec, t_length *length);
int					c_min(wchar_t c, t_lst *run);
int					c_n_min(wchar_t c, t_lst *run);
int					s_min(wchar_t *s, t_lst *run);
int					s_n_min(wchar_t *s, t_lst *run);
int					char_cs(va_list args, t_lst *run);
ssize_t				ft_atoi_n(const char *str);
void				*ft_realloc(void *array, size_t size);
t_lst				*ft_newlst(void);
void				clear_struct(t_lst *head);
void				ft_clear(char *width, char *accur, char *flag);
char				*ft_pointer(char *res, va_list args, t_lst *head);
int					ft_len(char *s);
int					search_base(t_sp *spec);
void				print_color(t_color *col);
void				ft_reset(t_color *col);
int					numsize(size_t n);
int					is_neg(ssize_t n);
int					active_bits(unsigned int c);
void				size_till_11(unsigned int v);
void				size_till_16(unsigned int v);
void				size_after_16(unsigned int v);
void				size_till_7(unsigned int v);
int					byte_num(int size);
int					if_n_min_add(t_lst *run, char *num);
int					if_n_min_add2(t_lst *run, char *num);
int					if_not_minus(t_lst *run, char *num);
int					ft_typing(va_list args, t_lst *head);
char				*ft_typing_add(va_list args, t_lst *head, char *res);
int					ft_align(t_lst *run, char *num);

#endif
