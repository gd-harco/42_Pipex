/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:37:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/11 21:39:31 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>

int	main(void)
{
	char	*argv[4];
	char	path[] = "./push_swap.out";

	argv[0] = path;
	argv[1] = "59";
	argv[2] = "29";
	argv[3] = "69";
	if (execve(path, argv, __environ) == -1)
	{
		ft_printf("%s\n", strerror(errno));
	}
	return (0);
}
