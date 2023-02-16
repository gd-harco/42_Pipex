/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:35 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/15 15:02:23 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
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

int	main(int argc, char **argv, char *envp[])
{
	char	**paths;
	char	*cur_path;
	char	**new_argv;
	int		index;
	pid_t	pid1;

	index = 0;
	paths = get_path(envp);
	new_argv = malloc(sizeof (char *) * (argc + 1));
	new_argv[2] = NULL;
	cur_path = ft_strjoin(3, paths[index], "/", argv[1]);
	while (paths[index] && access(cur_path, X_OK) != 0)
	{
		index++;
		free(cur_path);
		cur_path = ft_strjoin(3, paths[index], "/", argv[1]);
	}
	new_argv[0] = cur_path;
	new_argv[1] = NULL;
	ft_free_split(paths);
	pid1 = fork();
	if (pid1 == -1)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		free(cur_path);
		free(new_argv);
		return (1);
	}
	if (pid1 == 0)
		execve(cur_path, new_argv, envp);
	free(cur_path);
	free(new_argv);

	return (0);
}
