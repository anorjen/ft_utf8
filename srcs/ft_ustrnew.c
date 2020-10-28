/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:19:53 by anorjen           #+#    #+#             */
/*   Updated: 2020/10/28 15:25:56 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

t_usym	*ft_ustrnew(size_t size)
{
	t_usym	*new_arr;

	new_arr = (t_usym *)malloc(sizeof(t_usym) * (size + 1));
	if (new_arr == NULL)
		return (NULL);
	ft_bzero(new_arr, sizeof(t_usym) * size + 1);
	return (new_arr);
}
