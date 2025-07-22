/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:47:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/22 17:33:01 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
int	findstart(const char *big, const char *little, size_t len)
{
	const char	*needle;
	const char	*haystack;
	size_t		i;
	int			j;

	if (!*little)
		return (-1);
	i = 0;
	j = 0;
	while (*big && len > 0)
	{
		haystack = big;
		needle = little;
		j++;
		while (i < len && (*haystack == *needle))
		{
			needle++;
			haystack++;
			i++;
		}
		if (!*needle)
			return (j);
		i = 0;
		big++;
		len--;
	}
	return (0);
}
*/
int ft_strcmp(const char *s1, const char *s2)
{
    size_t          i;
    unsigned char   *str1;
    unsigned char   *str2;

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
