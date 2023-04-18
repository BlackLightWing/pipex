/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:33 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/17 11:17:15 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	son(char **env, char **av, int infile, int fd[2])
{
	char	**cmd;
	char	*path;
	int		i;

	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd = ft_split(av[0], ' ');
	path = path_finding(env, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		perror("NO PATH");
	}
	i = 0;
	while (cmd[0][i])
		i++;
	cmd[0][i] = '\0';
	if (execve(path, cmd, env) == -1)
		msg_error("son error");
}

void	father(char **env, char **av, int outfile, int fd[2])
{
	char	**cmd;
	char	*path;
	int		i;

	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(av[0], ' ');
	path = path_finding(env, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		perror("NO PATH");
	}
	i = 0;
	while (cmd[0][i])
		i++;
	cmd[0][i] = '\0';
	if (execve(path, cmd, env) == -1)
		msg_error("father error");
}
