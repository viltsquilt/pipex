/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:15:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:05 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_h"

int	ft_parse_args()
{

}

char	*get_path(char *env, char *path)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_substr(ft_strcmp(env[i], "PATH"), env[i], ft_strlen(env[i]));
		i++;
	}
}

int	ft_parse_cmds(char *cmd)
{
	char	*path;
	char	**split;

	path = get_path(env, "PATH");
	split = ft_split(path, ":");
	while (split[i])
	{
		if (ft_strcmp(split[i], cmd) == 0)
			return (split[i]);
		i++;
	}
}
