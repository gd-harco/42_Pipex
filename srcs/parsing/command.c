/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:23:13 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/22 17:30:21 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab)
{
	int	i;

	i = 0;
	data->command_nb = argc - 3;
	data->command = malloc(sizeof(char **) * data->command_nb + 1);
	if (!data->command)
		clean_exit(path_tab, data);
	data->command[data->command_nb] = NULL;
	while(i < data->command_nb)
	{
		data->command[i] = get_cmd_and_arg(argv[i + 2], path_tab);
		i++;
	}
}

char **get_cmd_and_arg(char *argv, char **path_tab)
{
	char **cmd_array;
	char *temp;


	cmd_array = ft_split(argv, ' ');
	if (!cmd_array)
		return (NULL);
	if (access(cmd_array[0], R_OK | X_OK))
		return (cmd_array);
	//TODO Check the co;plete fole of the command
	while
	return (cmd_array);
}