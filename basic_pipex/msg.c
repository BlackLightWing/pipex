/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorbell <msorbell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:28:24 by msorbell          #+#    #+#             */
/*   Updated: 2023/04/05 12:03:32 by msorbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	cmd_not_found(char *cmd)
{
	write(2, "Command not found :", 21);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit (127);
}
