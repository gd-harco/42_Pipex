/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:54:40 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/24 13:59:07 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

static void	free_triple_array(char ***to_free);

void	clean_exit(char **tab_to_free, t_pipex *data)
{
	if (tab_to_free)
	{
		ft_free_split(tab_to_free);
		ft_putstr_fd("clean exit message : ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	if (data)
		clean_struct(data);
	exit (1);
}

void	my_perror(char *variable)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(variable, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	clean_struct(t_pipex *data)
{
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->command)
		free_triple_array(data->command);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	if (data->infile_fd != -1)
		close(data->infile_fd);
}

static void	free_triple_array(char ***to_free)
{
	int i = 0;
	while (to_free[i])
	{
		ft_free_array((void **)to_free[i]);
		i++;
	}
	free(to_free);
}
