/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:35:27 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:36 by msorbell         ###   ########.fr       */
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

	pipex.out = outfile(av, ac - 1);
	if (strncmp(av[1], "here_doc", 8) == 0)
	{
		here_doc(av[2]);
		piping(ac, av, env, 3);
	}
	else
	{
		pipex.in = infile(av);
		dup2(pipex.in, STDIN_FILENO);
		piping(ac, av, env, 2);
	}
	dup2(pipex.out, STDOUT_FILENO);
	father_bonus(env, av[ac - 2]);
	return (0);
}
