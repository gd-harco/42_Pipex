/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/24 14:15:59 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse_file(t_pipex *data, char **argv, int argc)
{
	data->infile = ft_strdup(argv[1]);
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd == -1)
		my_perror(data->infile);
	data->outfile = ft_strdup(argv[argc-1]);
	data->outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		my_perror(data->outfile);
}
