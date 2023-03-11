/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:37:17 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/11 13:37:17 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:28:23 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/10 16:51:36 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_pid(t_pipex data);
static void	duplicate_fds(t_pipex *data, int i);

void	cmd_exec(t_pipex data, char **envp)
{
	int		cur_cmd;

	cur_cmd = 0;
	if (data.file_error)
		cur_cmd = 1;
	dup2(data.infile_fd, STDIN_FILENO);
	while (cur_cmd < data.command_nb)
	{
		ft_putendl_fd("help", 1);
	}
	wait_pid(data);
}

static void	wait_pid(t_pipex data)
{
	int	i;

	i = 0;
	while (i <= data.command_nb)
	{
		waitpid(data.pids[i], NULL, 0);
		i++;
	}
}

static void	duplicate_fds(t_pipex *data, int i)
{
	if (i == 0)
	{
		if (dup2(data->infile_fd, STDIN_FILENO) == -1)
			exit(3);
		close(data->infile_fd);
	}
	else
	{
		if (dup2(data->fds[i - 1][0], STDIN_FILENO) == -1)
			exit(3);
		close(data->fds[i - 1][0]);
	}
	if (i == data->command_nb - 1)
	{
		if (dup2(data->outfile, STDOUT_FILENO) == -1)
			exit(3);
		close(data->outfile);
	}
	else
	{
		if (dup2(data->fds[i][1], STDOUT_FILENO) == -1)
			exit(3);
		close(data->fds[i][1]);
	}
}
