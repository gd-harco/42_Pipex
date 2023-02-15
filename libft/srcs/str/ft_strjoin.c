/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:48:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/14 16:42:59 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:32:49 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/21 22:32:49 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "memory.h"
#include <stdio.h>

static char	*ft_strjoin_util(char const *s1, char const *s2);
static char	*joning(char *result, char *s2, char *s1);

char	*ft_strjoin(int str_nb, ...)
{
	va_list	args;
	char	*result;
	char	*tmp;
	char	*current_str;
	int		current_place;

	current_place = -1;
	va_start(args, str_nb);
	result = NULL;
	while (++current_place < str_nb)
	{
		current_str = va_arg(args, char *);
		tmp = result;
		if (tmp)
		{
			result = ft_strjoin_util(tmp, current_str);
			free(tmp);
			if (result == NULL)
				return (NULL);
		}
		else
			result = ft_strdup(current_str);
	}
	va_end(args);
	return (result);
}

static char	*joning(char *result, char *s2, char *s1)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (s1[x])
	{
		result[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		result[x] = s2[y];
		x++;
		y++;
	}
	result[x] = '\0';
	return (result);
}

static char	*ft_strjoin_util(char const *s1, char const *s2)
{
	size_t		joined_size;
	char		*result;
	size_t		size_s1;
	size_t		size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen (s1);
	size_s2 = ft_strlen (s2);
	joined_size = (size_s1 + size_s2);
	result = malloc(sizeof(char) * joined_size + 1);
	if (!result)
		return (NULL);
	return (joning(result, (char *)s2, (char *)s1));
}
