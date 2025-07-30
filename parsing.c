/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/30 11:56:04 by vahdekiv         ###   ########.fr       */
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

	pipex.index = 0;
	pipex.string = "PATH";
	while (envp[pipex.index])
	{
		if (ft_strncmp(envp[pipex.index], pipex.string, 4) == 0)
			break ;
		pipex.index++;
	}
	pipex.len = newstrlen(envp[pipex.index], '\n');
	pipex.mysplit = ft_split(envp[pipex.index], ':');
//	pipex.index = 0;
	pipex.mypaths = malloc((countwords(pipex.mysplit) + 1) * sizeof(char *));
	if (!pipex.mypaths)
		return (ft_free(pipex.mysplit), NULL);
	pipex.mypaths = buildpath(&pipex);
	if (!pipex.mypaths)
		return (NULL);
//	while (pipex.mysplit[pipex.index])
//	{
//		pipex.mypaths[pipex.index] = ft_join(pipex.mysplit[pipex.index], "/");
//		if (!pipex.mypaths[pipex.index])
//		{
//			free(pipex.mypaths);
//			ft_free(pipex.mysplit);
//			return (NULL);
//		}
//		pipex.index++;
//	}
//	pipex.mypaths[pipex.index] = 0;
	ft_free(pipex.mysplit);
	return (pipex.mypaths);
}

char	**buildpath(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->mysplit[i])
	{
		pipex->mypaths[i] = ft_join(pipex->mysplit[i], "/");
		if (!pipex->mypaths[i])
		{
			free(pipex->mypaths);
			ft_free(pipex->mysplit);
			return (NULL);
		}
		i++;
	}
	pipex->mypaths[i] = 0;
	return (pipex->mypaths);
}
