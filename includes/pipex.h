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
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	***command;
	int		command_nb;
	int		infile_fd;
	int		outfile_fd;
	int		pipefd[2];
}				t_pipex;

//----------------------------------------------------------------error/
void	my_perror(char *variable);
void	clean_struct(t_pipex *data);
void	clean_exit(char **tab_to_free, t_pipex *data);

//----------------------------------------------------------------parsing/
void	parsing_full(t_pipex *data, char **argv, char **envp, int argc);
void	parse_file(t_pipex *data, char **argv, int argc);
void	parse_cmd(t_pipex *data, char **argv, int argc, char **path_tab);
char	**get_cmd_and_arg(char *argv, char **path_tab);


#endif
