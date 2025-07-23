/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/23 16:32:12 by vahdekiv         ###   ########.fr       */
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
	int		k;

	i = 0;
	j = 0;
	k = 0;
	s = "PATH";
	while (envp[i])
	{
		if (ft_strncmp(envp[i], s, 4) == 0)
			break;
		i++;
	}
	len = newstrlen(envp[i], '\n');
	pipex.mypaths = ft_split(envp[i], ':'); //malloc
	while (pipex.mypaths[k])
	{
		pipex.mypaths[k] = ft_join(pipex.mypaths[k], "/");
		k++;
	}
	if (!pipex.mypaths)
		return (free(pipex.path), -1);
	pipex.mycmdargs = ft_parse_args(av);
	while (pipex.mypaths[j])
	{
		cmd = ft_join(pipex.mypaths[j], av);
		execve(cmd, pipex.mycmdargs, envp);
		perror("Error");
		free(cmd);
		j++;
	}
	return (-1);
}
