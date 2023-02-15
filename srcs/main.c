/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:18:35 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/15 12:47:48 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:37:49 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/13 22:21:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	char	*path_str;
	char	**paths;
	char	*cur_path;
	char	**new_argv;
	int		index;

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
		return (1);
	index = 0;
	paths = ft_split(path_str, ':');
	free (path_str);
	new_argv = malloc(sizeof (char *) * (argc + 1));
	new_argv[2] = NULL;
	cur_path = ft_strjoin(3, paths[index], "/", argv[1]);
	while (paths[index] && access(cur_path, X_OK) != 0)
	{
		index++;
		cur_path = ft_strjoin(3, paths[index], "/", argv[1]);
	}
	new_argv[0] = cur_path;
	new_argv[1] = NULL;
	execve(cur_path, new_argv, envp);
	return (0);
}
