/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:37:17 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/11 15:22:27 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	initial_loop(t_pipex data, int cur_cmd, char **envp);
static void	wait_pid(t_pipex data);
static void	final_pipe(t_pipex *data);

void	cmd_exec(t_pipex data, char **envp)
{
	int		cur_cmd;

	cur_cmd = 0;
	if (data.file_error)
		cur_cmd = 1;
	else
		dup2(data.infile_fd, STDIN_FILENO);
	while (cur_cmd < data.command_nb - 1)
	{
		if (data.command[cur_cmd])
			initial_loop(data, cur_cmd, envp);
		cur_cmd++;
	}
	dup2(data.outfile_fd, STDOUT_FILENO);
	if (data.error)
		close(data.outfile_fd);
	data.pids[cur_cmd] = fork();
	if (data.pids[cur_cmd] == 0)
	{
		if (data.file_error)
			final_pipe(&data);
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0], &data);
	}
	wait_pid(data);
}

static void	initial_loop(t_pipex data, int cur_cmd, char **envp)
{
	data.error = false;
	pipe(data.pipefd);
	data.pids[cur_cmd] = fork();
	if (access(data.command[cur_cmd][0], X_OK) == -1)
	{
		data.error = true;
		close(data.pipefd[0]);
	}
	if (data.pids[cur_cmd] == 0)
	{
		close(data.pipefd[0]);
		dup2(data.pipefd[1], STDOUT_FILENO);
		close(data.pipefd[1]);
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0], &data);
	}
	else
	{
		if (data.error)
			close(data.infile_fd);
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

void	final_pipe(t_pipex *data)
{
	pipe(data->pipefd);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
