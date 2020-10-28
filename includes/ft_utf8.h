/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:34:30 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/28 18:32:44 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	unicode utf8 library
**	little-endian maintain
*/

#ifndef FT_UTF8_H
# define FT_UTF8_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# define UREAD_BUFF_SIZE 128

typedef uint32_t	t_usym;

typedef struct		s_unode
{
	char			data[UREAD_BUFF_SIZE];
	int				fd;
	struct s_unode	*next;
}					t_unode;

char		*ft_utoc(t_usym *s);
t_usym		*ft_ctou( char *s);

ssize_t		uwrite(int fd, t_usym *buf, size_t nsym);

int			ft_addnode(t_unode **lst, int fd, char *buf);
void		free_buf(t_unode **root);
size_t		count_usym(char *s, size_t *i);
char		*ft_strjoin_free(char *s1, char *s2);
ssize_t		uread(int fd, t_usym *buf, size_t nsym);

size_t		usym_size(char c);
size_t		ft_ustrlen(t_usym *str);
t_usym		*ft_ustrnew(size_t size);


#endif
