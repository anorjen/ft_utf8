/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:06:39 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/28 17:25:44 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

static t_unode	*ft_findfd(t_unode *lst, int fd, char *buf)
{
	while (lst)
	{
		if (fd == lst->fd)
		{
			ft_strcpy(buf, lst->data);
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

static char	*read_block(int fd)
{
	char	*buf;
	int		ret;

	if ((buf = ft_strnew(UREAD_BUFF_SIZE)) == NULL)
		return (NULL);
	if ((ret = read(fd, buf, UREAD_BUFF_SIZE)) <= 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

static void	init(char *line[], char **buf)
{
	line[0] = NULL;
	line[1] = NULL;
	*buf = ft_strnew(UREAD_BUFF_SIZE);
}

/*
**	symlen[0] - кол-во char в строке соответствующее кол-ву юникод символов
**	symlen[1] - кол-во юникод символов в строке
**	str[0] - строка со всеми прочитанными char
**	str[1] - строка char с целым кол-вом юникод символов
*/

static char	*get_line(t_unode **root, int fd, size_t *nsym)
{
	t_unode		*tmp;
	char		*buf;
	char		*str[2];
	size_t		symlen[2];

	init(str, &buf);
	if ((tmp = ft_findfd(*root, fd, buf)) == NULL)
		buf = read_block(fd);
	str[0] = ft_strjoin_free(str[0], buf);
	symlen[1] = count_usym(str[0], &symlen[0]);
	while (symlen[1] < *nsym)
	{
		if ((buf = read_block(fd)) == NULL)
			break ;
		str[0] = ft_strjoin_free(str[0], buf);
		symlen[1] = count_usym(str[0], &symlen[0]);
	}
	str[1] = ft_strnew(symlen[0]);
	ft_strncpy(str[1], str[0], symlen[0]);
	ft_strncpy(buf, &str[0][symlen[0] + 1], ft_strlen(str[0]) - symlen[0] + 1);
	free(str[0]);
	(!tmp ? (void)ft_addnode(root, fd, buf) : (void)ft_strcpy(tmp->data, buf));
	free(buf);
	*nsym = symlen[1];
	return (str[1]);
}

ssize_t		uread(int fd, t_usym *ustr, size_t nsym)
{
	static t_unode	*root;
	char			*line;
	t_usym			*tmp;

	if (nsym == 0)
	{
		free_buf(&root);
		return (0);
	}
	if (fd < 0 || fd == 1 || fd == 2 || ustr == NULL
		|| (line = get_line(&root, fd, &nsym)) == NULL)
		return (-1);
	tmp = ft_ctou(line);
	free(line);
	ft_memcpy(ustr, tmp, sizeof(t_usym) * nsym);
	free(tmp);
	return (nsym);
}
