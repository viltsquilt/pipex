/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/25 15:18:50 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_args(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	if (!args)
		return (perror("args"), NULL);
	return (args);
}

char	**ft_parse_cmds(char **envp)
{
	t_pipex	pipex;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	pipex.string = "PATH";
	while (envp[i])
	{
		if (ft_strncmp(envp[i], pipex.string, 4) == 0)
			break ;
		i++;
	}
	pipex.len = newstrlen(envp[i], '\n');
	pipex.mypaths = ft_split(envp[i], ':');
	while (pipex.mypaths[k])
	{
		pipex.mypaths[k] = ft_join(pipex.mypaths[k], "/");
		if (!pipex.mypaths[k])
			return (free(pipex.mypaths[k]), NULL);
		k++;
	}
	return (pipex.mypaths);
}
