/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:23:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/11 13:38:43 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd_path(char *path_tab, char *cmd);
static void	parse_file(t_pipex *data, char **argv, int argc);
static void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab);
static char	**get_cmd_and_arg(char *argv, char **path_tab);

void	parsing_full(t_pipex *data, char **argv, char **envp, int argc)
{
	char	**path_tab;
	char	*path_str;
	int		index;

	data->error = false;
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
		clean_exit(NULL, data);
	path_tab = ft_split(path_str, ':');
	free(path_str);
	parse_cmd(data, argv, argc, path_tab);
	ft_free_split(path_tab);
}

static void	parse_file(t_pipex *data, char **argv, int argc)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	data->file_error = false;
	if (data->infile_fd == -1)
	{
		my_perror(argv[1], data);
		data->file_error = true;
	}
	data->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		my_perror(argv[argc - 1], data);
}

static void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab)
{
	int	i;

	i = 0;
	data->command_nb = argc - 3;
	data->pids = malloc(sizeof(pid_t) * data->command_nb);
	data->command = malloc(sizeof(char **) * data->command_nb + 1);
	if (!data->command)
		clean_exit(path_tab, data);
	while (i < data->command_nb)
	{
		data->command[i] = get_cmd_and_arg(argv[i + 2], path_tab);
		i++;
	}
}

static char	**get_cmd_and_arg(char *argv, char **path_tab)
{
	char	**cmd_array;
	char	*cmd_path;
	int		i;

	i = -1;
	cmd_array = ft_split(argv, ' ');
	if (!cmd_array)
		return (NULL);
	if (ft_strncmp(cmd_array[0], "./", 2) == 0
		|| ft_strncmp(cmd_array[0], "/", 1) == 0)
		return (full_path(cmd_array));
	while (path_tab[++i])
	{
		cmd_path = get_cmd_path(path_tab[i], cmd_array[0]);
		if (access(cmd_path, R_OK | X_OK) != 0)
			free(cmd_path);
		else
		{
			free(cmd_array[0]);
			cmd_array[0] = cmd_path;
			return (cmd_array);
		}
	}
	my_perror(cmd_array[0], NULL);
	return (NULL);
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
