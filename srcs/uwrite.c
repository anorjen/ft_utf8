/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uwrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:06:27 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/22 19:14:01 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

ssize_t	uwrite(int fd,  uint32_t *buf, size_t n)
{
	char		*out;
	uint32_t	*tmp;

	tmp = (uint32_t*)malloc(sizeof(uint32_t)*n);
	ft_memcpy(tmp, buf, n * 4);
	if ((out = ft_utoc(tmp)) == NULL)
		return (-1);
	write(fd, out, ft_strlen(out));
	free(out);
	free(tmp);
	return (n);
}
