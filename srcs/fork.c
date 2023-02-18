/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:18:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/02/18 14:56:04 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include "../libft/includes/libft.h"

void print_error(int errno)
{

}


int main(int argc, char **argv)
{
	pid_t	id;
	int		fd[2];

	if(pipe(fd) == -1)
	{
		ft_printf(strerror(errno));
		return (1);
	}

	id = fork();
	if (id == -1)
	{
		ft_printf(strerror(errno));
		return (1);
	}
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number : ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("%d\n", y);
	}
	return 0;
}