/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:32:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/08 15:32:09 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**full_path(char **cmd_array)
{
	if (access(cmd_array[0], R_OK | X_OK) == 0)
		return (cmd_array);
	else
	{
		my_perror(cmd_array[0], NULL);
		exit(1);
	}
}
