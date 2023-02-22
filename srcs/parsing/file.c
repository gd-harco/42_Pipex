/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:08 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/22 14:52:08 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse_file(t_pipex *data, char **argv, int argc)
{
	data->infile = ft_strdup(argv[1]);
	data->outfile = ft_strdup(argv[argc-1]);
}