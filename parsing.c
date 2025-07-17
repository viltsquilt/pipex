/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/17 16:31:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_args(char **av)
{
	char	**mycmdargs;

	mycmdargs = ft_split(av[2], ' ');//malloc
	if (!mycmdargs)
		return (perror("mycmdargs"), NULL);
	return (mycmdargs);
}

int	newstrlen(char **envp, char *start, char c)
{
	int	len;
	int	i;

	i = start;
	while (envp[i])
	{
		if (envp[i] == c)
			break;
		i++;
	}
	len = i - start;
	return (len);
}

char	*ft_parse_cmds(char *cmd, char **envp)
{
	char	*path;
	char	*start;
	char	*s;
	int		len;
	int		i;
	char	**mypaths;

	i = 0;
	s = "PATH";
	len = ft_strlen(*envp);
	start = ft_strnstr(*envp, s, len);
	len = newstrlen(envp, start, '\n');
	path = ft_substr(*envp, start, len); //malloc
	if (!path)
		perror("path");
	mypaths = ft_split(path, ':'); //malloc
	if (!mypaths)
		return (free(path), 1);
	while (mypaths[i])
	{
		if (ft_strncmp(mypaths[i], cmd) == 0)
			return (mypaths[i]);
		i++;
	}
	return (0);
}
