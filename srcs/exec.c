/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:28:23 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/08 12:13:38 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	initial_loop(t_pipex data, int cur_cmd, char **envp);
static void	wait_pid(t_pipex data);

void	cmd_exec(t_pipex data, char **envp)
{
	int		cur_cmd;

	cur_cmd = 0;
	dup2(data.infile_fd, STDIN_FILENO);
	while (cur_cmd < data.command_nb - 1)
	{
		initial_loop(data, cur_cmd, envp);
		cur_cmd++;
	}
	dup2(data.outfile_fd, STDOUT_FILENO);
	data.pids[cur_cmd] = fork();
	if (data.pids[cur_cmd] == 0)
	{
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0]);
	}
	wait_pid(data);
}

static void	initial_loop(t_pipex data, int cur_cmd, char **envp)
{
	pipe(data.pipefd);
	data.pids[cur_cmd] = fork();
	if (data.pids[cur_cmd] == 0)
	{
		close(data.pipefd[0]);
		dup2(data.pipefd[1], STDOUT_FILENO);
		close(data.pipefd[1]);
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0]);
	}
	else
	{
		close(data.pipefd[1]);
		dup2(data.pipefd[0], STDIN_FILENO);
		close(data.pipefd[0]);
	}
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
