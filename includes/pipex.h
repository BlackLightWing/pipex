/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:33:05 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/18 14:09:50 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "../libft/libft.h"

typedef struct pipex
{
	int	*fd;
	int	in;
	int	out;
	int	id;
	int	i;
}	t_p;

//----------------------------------------//
//-------------Path Finding---------------//
//----------------------------------------//
char	*trunc_path(char **path, char **path_join, char *cmd);
char	*path_finding(char **env, char *cmd);
int		infile(char **av);
int		outfile(char **av, int ac);

//----------------------------------------//
//------------------core------------------//
//----------------------------------------//
void	father_bonus(char **env, char *av);
void	son_bonus(char **env, char *av, int fd[2]);
void	son(char **env, char **av, int infile, int fd[2]);
void	father(char **env, char **av, int outfile, int fd[2]);
void	piping(int ac, char **av, char **env, int i);
void	here_doc(char *limiter);

//----------------------------------------//
//-------------Error messages-------------//
//----------------------------------------//
void	msg_error(char *err);
void	cmd_not_found(char *cmd);
void	ft_free(char **str);

#endif
