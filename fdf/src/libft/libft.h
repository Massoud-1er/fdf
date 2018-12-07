/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 22:02:54 by mmovahhe          #+#    #+#             */
/*   Updated: 2018/11/29 22:26:31 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_subfree(const char *s, unsigned int start, size_t len);

char				*ft_dupfree(const char *src);

char				*ft_joinfree(char const *s1, char const *s2);

char				**ft_megamalloc(char *s, char c);

void				ft_d(char *str);

int					ft_c_w(const char *s, char c);

char				**ft_mega_malloc(char *s, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstcpy (t_list *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_lstlen(t_list *lst);

int					ft_lstlen(t_list *lst);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memset(void *b, int c, size_t len);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

char				*ft_strrev(char *s);

char				*ft_strdup(const char *s1);

char				*ft_strdup_until(const char *s1, int len);

size_t				ft_abs(int i);

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

size_t				ft_strlen(char const *s);

int					ft_sizeofint(int n);

char				*ft_strrev(char *s);

int					ft_pow(int nb, int pow);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

int					ft_tolower(int c);

int					ft_toupper(int c);

char				*ft_strtolower(char *str);

char				*ft_strtoupper(char *str);

void				ft_strtocapitalize(char *str);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

char				*ft_strcasestr(const char *haystack, const char *needle);

char				*ft_strcat(char *s1, const char *s2);

int					ft_word_count(char *str, char c);

char				**ft_strsplit(char const *s, char c);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif