/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:37:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/13 22:21:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>

int	main(int argc, char **argv, char *envp[])
{
	char	*my_argv[5];
	char	path[] = "/usr/bin/ls";


	my_argv[0] = path;
	my_argv[1] = NULL;
	if (execve(path, my_argv, __environ) == -1)
	{
		ft_printf("%s\n", strerror(errno));
	}
	return (0);
}
