/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>                                */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:46:40 by gd-harco          #+#    #+#             */
/*   Updated: 2022/11/07 14:21:37 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "/nfs/homes/gd-harco/Documents/libft/includes/memory.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		((char *)s)[x] = '\0';
		x++;
	}
}
