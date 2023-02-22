/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:02:04 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/15 13:05:23 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	***command;
}				t_pipex;

#endif