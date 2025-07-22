/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/22 13:39:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_args(char **av)
{
	t_pipex	pipex;

	pipex.mycmdargs = ft_split(av[2], ' ');//malloc
	if (!pipex.mycmdargs)
		return (perror("mycmdargs"), NULL);
	return (pipex.mycmdargs);
}

int	newstrlen(char **envp, int start, char c)
{
	int	len;
	int	i;

	i = start;
	while (envp[i])
	{
		if (*envp[i] == c)
			break;
		i++;
	}
	len = i - start;
	return (len);
}

char	*ft_parse_cmds(char *cmd, char **envp)
{
	t_pipex	pipex;
	int		start;
	char	*s;
	int		len;
	int		i;

	i = 0;
	s = "PATH";
	len = ft_strlen(*envp);
	start = findstart(*envp, s, len);
	len = newstrlen(envp, start, '\n');
	pipex.path = ft_substr(*envp, start, len); //malloc
	if (!pipex.path)
		perror("path");
	pipex.mypaths = ft_split(pipex.path, ':'); //malloc
	if (!pipex.mypaths)
		return (free(pipex.path), NULL);
	while (pipex.mypaths[i])
	{
		if (ft_strcmp(pipex.mypaths[i], cmd) == 0)
			return (pipex.mypaths[i]);
		i++;
	}
	return (0);
}
