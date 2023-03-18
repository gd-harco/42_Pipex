/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:15:35 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/18 13:15:35 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:54:40 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/16 15:30:45 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_triple_array(t_pipex *data);

void	clean_exit(char **tab_to_free, t_pipex *data)
{
	if (tab_to_free)
	{
		ft_free_split(tab_to_free);
	}
	if (data)
		clean_struct(data);
	exit (1);
}

void	my_perror(char *variable, t_pipex *data)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(variable, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (data)
		data->error = true;
}

void	clean_struct(t_pipex *data)
{
	if (data->command)
		free_triple_array(data);
	if (data->pids)
		free(data->pids);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	if (data->infile_fd != -1)
		close(data->infile_fd);
}

static void	free_triple_array(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->command_nb)
	{
		ft_free_array((void **)data->command[i]);
		i++;
	}
	free(data->command);
}
