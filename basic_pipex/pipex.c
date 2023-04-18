/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:35:27 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/14 14:28:09 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile(char **av)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		perror("bash");
	return (infile);
}

int	outfile(char **av, int ac)
{
	int	outfile;

	outfile = open(av[ac], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	return (outfile);
}

int	main(int ac, char **av, char **env)
{
	t_p	pipex;
	int	fd[2];

	if (ac == 5)
	{
		pipex.in = infile(av);
		pipex.out = outfile(av, ac - 1);
		if (pipe(fd) < 0)
			msg_error("Error pipe :");
		pipex.id = fork();
		if (pipex.id < 0)
			msg_error("Error fork :");
		if (pipex.id == 0)
			son(env, &av[2], pipex.in, fd);
		father(env, &av[3], pipex.out, fd);
	}
	else
		msg_error("Invalid Number of Argument\n");
	system("leaks pipex");
	return (0);
}
