/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:21:30 by agottlie          #+#    #+#             */
/*   Updated: 2020/10/28 15:41:59 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while ((src[i] != '\0' || dst[i] != '\0') && i < len)
	{
		if (src[i] == '\0')
		{
			dst[i] = src[i];
			++i;
			break ;
		}
		dst[i] = src[i];
		++i;
	}
	if (i < len - 1)
		while (dst[i] != '\0' && i < len)
		{
			dst[i] = '\0';
			++i;
		}
	return (dst);
}
