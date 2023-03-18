/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:50:40 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/17 16:46:24 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_valid_arg(int argc, t_pipex *data)
{
	if (argc < 5)
	{
		ft_putendl_fd("Too few argument provided", STDERR_FILENO);
		ft_putendl_fd("Usage : ./pipex file1 cmd1 cmd2 file2", STDERR_FILENO);
		return (false);
	}
	if (argc > 5)
	{
		ft_putendl_fd("Too many argument provided", STDERR_FILENO);
		ft_putendl_fd("Usage : ./pipex file1 cmd1 cmd2 file2", STDERR_FILENO);
		return (false);
	}
	data->command_nb = argc - 3;
	return (true);
}

char	**full_path(char **cmd_array)
{
	if (access(cmd_array[0], R_OK | X_OK) == 0)
		return (cmd_array);
	else
	{
		my_perror(cmd_array[0], NULL);
		exit(1);
	}
}
