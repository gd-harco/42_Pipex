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

static char	**get_path(char **envp);

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	data;
	char	**path_tab;
	pid_t	pid;

	parse_file(&data, argv, argc);
	path_tab = get_path(envp);
	parse_cmd(&data, argv, argc, path_tab);
	ft_printf("fork done\n");
	if (pid == -1)
		clean_exit(path_tab, &data);
	if (pid == 0) {
		wait(NULL);
		ft_printf("Worked ?\n");
	}else
	{
//		launch_function(argv[1], argv[2], path_tab, envp);
	}
	ft_free_split(path_tab);
	return (0);
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
