/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:29:47 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/17 12:48:17 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*trunc_path(char **path, char **path_join, char *cmd)
{
	int		i;

	i = 0;
	while (path[i])
	{
		path_join[i] = ft_strjoin(path[i], cmd);
		if (access(path_join[i], F_OK) != -1)
		{
			if (access(path_join[i], X_OK) != -1)
			{
				ft_free(path);
				return (path_join[i]);
			}
			ft_free(path);
		}
		i++;
	}
	return (0);
}

char	*path_finding(char **env, char *cmd)
{
	int		i;
	char	**full_path;
	char	**path_join;
	char	*last_path;
	char	*cmd_path;

	i = 0;
	cmd_path = ft_strjoin("/", cmd);
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	full_path = ft_split(&env[i][5], ':');
	i = 0;
	while (full_path[i])
		i++;
	path_join = ft_calloc(i, sizeof(char *));
	last_path = trunc_path(full_path, path_join, cmd_path);
	free(cmd_path);
	free(path_join);
	if (last_path == NULL)
		cmd_not_found(cmd);
	return (last_path);
}
