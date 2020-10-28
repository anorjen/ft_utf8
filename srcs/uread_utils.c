/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uread_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:39:36 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/28 15:38:39 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

int		ft_addnode(t_unode **lst, int fd, char *buf)
{
	t_unode	*new;

	if ((new = (t_unode *)malloc(sizeof(t_unode))) == NULL)
		return (-1);
	new->fd = fd;
	ft_strcpy(new->data, buf);
	new->next = NULL;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		(*lst) = new;
	return (1);
}

void	free_buf(t_unode **root)
{
	t_unode	*cur;
	t_unode	*next;

	if (root && *root)
	{
		cur = *root;
		while (cur)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
		*root = NULL;
	}
}

size_t	count_usym(char *s, size_t *i)
{
	size_t	res;
	size_t	l;
	size_t	t;

	res = 0;
	*i = 0;
	while (s && s[*i])
	{
		l = usym_size(s[*i]);
		if (l == 0)
			++(*i);
		else
		{
			t = *i;
			while (s[t] && --l > 0)
				++t;
			if (l != 0)
				break ;
			else
				*i = t;
		}
		++res;
	}
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (res);
}
