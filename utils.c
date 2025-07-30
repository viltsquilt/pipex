/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:47:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/30 11:56:16 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_join(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*newstr;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		newstr = malloc(len1 + len2 + 1);
		if (!newstr)
			return (NULL);
		ft_memcpy(newstr, s1, len1);
		ft_memcpy(newstr + len1, s2, len2);
		newstr[len1 + len2] = '\0';
		return ((char *) newstr);
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	newstrlen(char *envp, char c)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i] == c)
			break ;
		i++;
	}
	return (i);
}

void	ft_free(char **arg)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (arg[index])
		index++;
	while (i <= index)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

int	countwords(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
