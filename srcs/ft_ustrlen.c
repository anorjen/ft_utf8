/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:16:39 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/22 18:43:12 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

size_t	ft_ustrlen( uint32_t *s)
{
	size_t	i;

	if (s == NULL || *s == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
		++i;
	return (i);
}
