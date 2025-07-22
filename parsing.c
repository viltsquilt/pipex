/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/22 18:27:19 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_args(char *av)
{
	char **args;

	args = ft_split(av, ' ');//malloc
	if (!args)
		return (perror("args"), NULL);
	return (args);
}

int	newstrlen(char *envp, char c)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == c)
			break;
		i++;
	}
	return (i);
}

int	ft_parse_cmds(char *cmd, char *av, char **envp)
{
	t_pipex	pipex;
	char	*s;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = "PATH";
	while (envp[i])
	{
		if (ft_strncmp(envp[i], s, 4) == 0)
			break;
		i++;
	}
	len = newstrlen(envp[i], '\n');
	pipex.mypaths = ft_split(envp[i], ':'); //malloc
	if (!pipex.mypaths)
		return (free(pipex.path), -1);
	pipex.mycmdargs = ft_parse_args(av);
	while (pipex.mypaths[j])
	{
		cmd = ft_strjoin(pipex.mypaths[j], av);
		execve(cmd, pipex.mycmdargs, envp);
		perror("Error");
		free(cmd);
		j++;
//		if (ft_strcmp(pipex.mypaths[j], cmd) == 0)
//			return (pipex.mypaths[j]);
//		j++;
	}
	return (-1);
}
