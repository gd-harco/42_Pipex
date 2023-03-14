/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:16:53 by gd-harco          #+#    #+#             */
/*   Updated: 2023/03/11 15:33:13 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	data;

	if (envp[0] == NULL)
		exit (1);
	if (!check_valid_arg(argc, &data))
		exit (3);
	parsing_full(&data, argv, envp, argc);
	cmd_exec(data, envp);
	clean_struct(&data);
	return (0);
}
