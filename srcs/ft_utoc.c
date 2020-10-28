/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:13:10 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/28 18:29:00 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

static size_t	input(char *buf, uint32_t c)
{
	unsigned char	s[4];
	int				i;
	size_t			ret;

	i = 4;
	while (--i >= 0)
	{
		s[3 - i] = (c >> (8 * i)) & 0xff;
	}
	ret = 0;
	i = 4;
	while (--i >= 0)
	{
		if (s[i] > 0)
		{
			*(buf++) = s[i];
			++ret;
		}
	}
	return (ret);
}

char	*ft_utoc( uint32_t *s)
{
	size_t	i;
	size_t	ret;
	char	*out;
	char	*tmp;

	if ((out = (char*)malloc(sizeof(uint32_t) * ft_ustrlen(s))) == NULL)
		return (NULL);
	tmp = out;
	i = -1;
	while (s[++i] != 0)
	{
		if (s[i] < 128)
			*(tmp++) = (char)s[i];
		else
		{
			ret = input(tmp, s[i]);
			tmp += ret;
		}
	}
	tmp = 0;
	return (out);
}
