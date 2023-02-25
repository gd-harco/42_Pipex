/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:47:17 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/24 17:21:03 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	data;
	int		cur_cmd;
	pid_t	pid;

	if (argc < 5)
		return (0);
	cur_cmd = 0;
	parsing_full(&data, argv, envp, argc);
	dup2(data.infile_fd, STDIN_FILENO);
	while (cur_cmd < data.command_nb - 1)
	{
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
	clean_struct(&data);
	return (0);
}
