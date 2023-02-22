/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:47:17 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/22 13:59:25 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clean_exit(char **tab_to_free);
static char	**get_path(char **envp);
static void	launch_fonction(char *in_file, char *command,
				char **path_tab, char **envp);

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	data;
	char	**path_tab;
	int		pipe_fd[2];
	pid_t	pid;

	(void)argc;
	path_tab = get_path(envp);
//	if (pipe(pipe_fd) == -1)
//		clean_exit(path_tab);
	ft_printf("\npipe done\n");
	pid = fork();
	ft_printf("fork done\n");
	if (pid == -1)
		clean_exit(path_tab);
	if (pid == 0) {
		wait(NULL);
		ft_printf("Worked ?\n");
	}else
	{
		launch_fonction(argv[1], argv[2], path_tab, envp);

	}
	ft_free_split(path_tab);
	return (0);
}

static void	clean_exit(char **tab_to_free)
{
	ft_free_split(tab_to_free);
	ft_putstr_fd("clean exit message : ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	exit (1);
}

static char	**get_path(char **envp)
{
	char	*path_str;
	int		index;
	char	**result;

	index = 0;
	path_str = NULL;
	while (*envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			path_str = ft_strpdup(envp[index], 5);
			break ;
		}
		index++;
	}
	if (!path_str)
		exit (1);
	result = (ft_split(path_str, ':'));
	free(path_str);
	return (result);
}

static void	launch_fonction(char *in_file, char *command,
				char **path_tab, char **envp)
{
	int		i;
	char	*cur_path;
	char	**new_arg;
	int		infile_fd;

	infile_fd = open(in_file, O_RDONLY);
	dup2(infile_fd, STDIN_FILENO);
	new_arg = malloc(sizeof(char *) * 2);
	if (!new_arg)
		clean_exit(path_tab);
	new_arg[0] = NULL;
	new_arg[1] = NULL;
	i = 0;
	if (access(command, X_OK) == -1)
	{
		while (path_tab[i])
		{
			cur_path = ft_strjoin(3, path_tab[i], "/", command);
			if (access(cur_path, X_OK) == -1)
				i++;
			else
				break;
			free(cur_path);
		}
		new_arg[0] = cur_path;
	}
	else
		new_arg[0] = command;
	execve(new_arg[0], new_arg, envp);
	ft_free_array((void **)new_arg);
	clean_exit(path_tab);
}
