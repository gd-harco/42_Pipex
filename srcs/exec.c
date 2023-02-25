/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:28:23 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/25 13:41:00 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	initial_loop(t_pipex data, int cur_cmd, char **envp);

void	cmd_exec(t_pipex data, char **envp)
{
	int		cur_cmd;
	pid_t	pid;

	cur_cmd = 0;
	dup2(data.infile_fd, STDIN_FILENO);
	while (cur_cmd < data.command_nb - 1)
	{
		initial_loop(data, cur_cmd, envp);
		cur_cmd++;
	}
	dup2(data.outfile_fd, STDOUT_FILENO);
	pipe(data.pipefd);
	pid = fork();
	if (pid == 0)
	{
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0]);
	}
	else
		wait(NULL);
}

static void	initial_loop(t_pipex data, int cur_cmd, char **envp)
{
	pid_t	pid;

	pipe(data.pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(data.pipefd[0]);
		dup2(data.pipefd[1], STDOUT_FILENO);
		close(data.pipefd[1]);
		execve(data.command[cur_cmd][0], data.command[cur_cmd], envp);
		my_perror(data.command[cur_cmd][0]);
	}
	else
	{
		wait(NULL);
		close(data.pipefd[1]);
		dup2(data.pipefd[0], STDIN_FILENO);
		close(data.pipefd[0]);
	}
}
