/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:33 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/18 14:12:12 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	son_bonus(char **env, char *av, int fd[2])
{
	char	**cmd;
	char	*path;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	cmd = ft_split(av, ' ');
	path = path_finding(env, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		perror("NO PATH");
	}
	if (execve(path, cmd, env) == -1)
		msg_error(path);
}

void	father_bonus(char **env, char *av)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = path_finding(env, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		perror("NO PATH");
	}
	if (execve(path, cmd, env) == -1)
		msg_error(path);
}

void	piping(int ac, char **av, char **env, int i)
{
	int	fd[2];
	t_p	pipex;

	while (i < ac - 2)
	{
		if (pipe(fd) < 0)
			msg_error("Error pipe :");
		pipex.id = fork();
		if (pipex.id < 0)
			msg_error("Error fork :");
		if (pipex.id == 0)
			son_bonus(env, av[i], fd);
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
		}
		i++;
	}
}

void	here_doc(char *limiter)
{
	char	*line;
	int		fd[2];
	int		i;

	if (pipe(fd) == -1)
		msg_error("(here_doc)pipe error :");
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		i = ft_strlen(line);
		line[i] = '\0';
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}
