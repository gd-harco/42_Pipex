/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:47:17 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/09 12:04:28 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	data;

	if (envp[0] == NULL)
		exit (1);
	if (argc < 5)
	{
		ft_putstr_fd("Too few argument provided, exiting\n", 2);
		return (0);
	}
	if (argc > 5)
	{
		ft_putstr_fd("Too many argument provided, exiting\n", 2);
		return (0);
	}
	parsing_full(&data, argv, envp, argc);
	cmd_exec(data, envp);
	clean_struct(&data);
	return (0);
}
