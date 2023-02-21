/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:35 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/21 11:28:52 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clean_exit(char **tab_to_free);
static char	**get_path(char **envp);
static void	launch_fonction(char *in_file, char *command,
				char **path_tab, char **envp);

int	main(int argc, char **argv, char *envp[])
{
	char	**path_tab;
	int		pipe_fd[2];
	pid_t	pid;

	(void)argc;
	path_tab = get_path(envp);
	if (pipe(pipe_fd) == -1)
		clean_exit(path_tab);
	pid = fork();
	if (pid == -1)
		clean_exit(path_tab);
	if (pid == 0)
		launch_fonction(argv[1], argv[2], path_tab, envp);
	else
	{
		wait(NULL);
		ft_printf("Worked ?\n");
	}
	ft_free_split(path_tab);
	return (0);
}

static void	clean_exit(char **tab_to_free)
{
	ft_free_split(tab_to_free);
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

	new_arg = malloc(sizeof(char *) * 3);
	new_arg[1] = in_file;
	new_arg[2] = NULL;
	i = 0;
	while (path_tab[i])
	{
		cur_path = ft_strjoin(3, path_tab[i], "/", command);
		if (access(cur))
		i++;
		free(cur_path);
	}
	execve(cur_path, new_arg, envp);
	ft_free_array((void **)new_arg);
	clean_exit(path_tab);
}
