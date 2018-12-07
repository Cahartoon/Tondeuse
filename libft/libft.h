/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:36:42 by edinguim          #+#    #+#             */
/*   Updated: 2018/12/07 12:31:08 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 8

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_print
{
	char			*fmt;
	char			result[4000];
	size_t			size;
	size_t			buff_i;
	size_t			fmt_i;
	char			conv;
	int				f_hash;
	int				f_zero;
	int				f_moins;
	int				f_plus;
	int				f_space;
	int				m_h;
	int				m_hh;
	int				m_l;
	int				m_ll;
	int				m_j;
	int				m_z;
	int				n_neg;
	int				precision;
	int				width;
	va_list			arg;
}					t_print;

void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_puttab(char **tab);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *s);
char				*ft_itoa(int n);
char				*ft_ltoa(intmax_t n);
char				*ft_utoa_base(unsigned long long n, int base);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *s, char c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t l);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_joinfree(char *s1, char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
size_t				ft_strword(const char *s, char c);
char				*ft_tabcat(const char **tab);
char				*ft_tabccat(const char **tab, const char *s);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alist, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nlst);
void				ft_lstappend(t_list *head, t_list *nlst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int c, size_t l);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isnumber(char *s);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strsrch(const char *s, int c);
size_t				ft_intsize(int n);
size_t				ft_intmaxsize(intmax_t n);
int					get_next_line(int fd, char **line);
int					ft_getopt(int ac, const char **av, const char *opstr);
int					ft_printf(const char *fmt, ...);
void				ft_printf_add_char(t_print *p, const char *fmt);
void				ft_printf_add_conv(t_print *p, char *s);
void				ft_printf_buffer(t_print *p);
void				ft_printf_c(t_print *p);
void				ft_printf_conv(t_print *p);
void				ft_printf_di(t_print *p);
void				ft_printf_flags(t_print *p, char *s, char *prefix);
void				ft_printf_majc(t_print *p);
void				ft_printf_majd(t_print *p);
void				ft_printf_majo(t_print *p);
void				ft_printf_majs(t_print *p);
void				ft_printf_maju(t_print *p);
void				ft_printf_modulo(t_print *p);
void				ft_printf_oux(t_print *p);
void				ft_printf_p(t_print *p);
void				ft_printf_parse(t_print *p, const char *fmt);
void				ft_printf_s(t_print *p);
int					ft_printf_unicode(unsigned char *buff, int c);

#endif
