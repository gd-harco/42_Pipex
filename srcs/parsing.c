/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:23:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/25 13:04:05 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd_path(char *path_tab, char *cmd);

void	parsing_full(t_pipex *data, char **argv, char **envp, int argc)
{
	char	**path_tab;
	char	*path_str;
	int		index;

	parse_file(data, argv, argc);
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
	path_tab = ft_split(path_str, ':');
	free(path_str);
	parse_cmd(data, argv, argc, path_tab);
	ft_free_split(path_tab);
}

void	parse_file(t_pipex *data, char **argv, int argc)
{
	data->infile = ft_strdup(argv[1]);
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd == -1)
		my_perror(data->infile);
	data->outfile = ft_strdup(argv[argc - 1]);
	data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		my_perror(data->outfile);
}

void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab)
{
	int	i;

	i = 0;
	data->command_nb = argc - 3;
	data->command = malloc(sizeof(char **) * data->command_nb + 1);
	if (!data->command)
		clean_exit(path_tab, data);
	while (i < data->command_nb)
	{
		data->command[i] = get_cmd_and_arg(argv[i + 2], path_tab);
		i++;
	}
}

char	**get_cmd_and_arg(char *argv, char **path_tab)
{
	char	**cmd_array;
	char	*cmd_path;
	int		i;

	i = -1;
	cmd_array = ft_split(argv, ' ');
	if (!cmd_array)
		return (NULL);
	if (access(cmd_array[0], R_OK | X_OK) == 0)
		return (cmd_array);
	while (path_tab[++i])
	{
		cmd_path = get_cmd_path(path_tab[i], cmd_array[0]);
		if (access(cmd_path, R_OK | X_OK) != 0)
			free(cmd_path);
		else
		{
			free(cmd_array[0]);
			cmd_array[0] = cmd_path;
			break ;
		}
	}
	return (cmd_array);
}

static char	*get_cmd_path(char *path_tab, char *cmd)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(path_tab, "/");
	result = ft_strjoin(temp, cmd);
	free(temp);
	return (result);
}
