/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:37:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/10 15:37:49 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/includes/libft.h"
#include <string.h>

int main(void)
{
	for (int i = 0; i < 250; i++)
		ft_printf("Error number : %i, Error message : %s\n",i, strerror(i));
	return (0);
}