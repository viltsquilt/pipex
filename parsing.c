/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/15 15:30:45 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_h"

int	ft_parse_args(char	**av)
{
	char	*mycmdargs;

	mycmdargs = ft_split(av[2], " ");//malloc
	if (!mycmdargs)
		return (perror("mycmdargs");
	return (mycmdargs);
}

int	newstrlen(char **envp, int start, char c)
{
	int	len;
	int	i;

	i = start;
	while (envp[start])
	{
		if (envp[start] == c)
			break;
		start++;
	}
	len = start - i;
	return (len);
}

int	ft_parse_cmds(char *cmd, char **envp);
{
	char	*path;
	char	**split;
	int		start;
	char	*s;
	int		len;
	int		i;

	i = 0;
	s = "PATH";
	len = ft_strlen(envp);
	start = ft_strnstr(envp, s, len);
	len = newstrlen(envp, start, "\n");
	path = ft_substr(envp, start, len); //malloc
	if (!path)
		return (perror("path"));
	mypaths = ft_split(path, ":"); //malloc
	if (!mypaths)
		return (free(path), 1);
	while (mypaths[i])
	{
		if (ft_strcmp(mypaths[i], cmd) == 0)
			return (mypaths[i]);
		i++;
	}
	return (0);
}
