/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/22 14:52:08 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab)
{
	int	i;

	i = 0;
	data->command_nb = argc - 3;
	data->command = malloc(sizeof(char **) * data->command_nb);
	if (!data->command)
		exit
	while(i < data->command_nb)
	{
		get_cmd_path()
	}
}