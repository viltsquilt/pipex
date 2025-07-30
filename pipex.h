/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/30 14:15:55 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h> 
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		len;
	int		file[2];
	int		pipes[2];
	int		index;
	char	*cmd;
	char	*string;
	char	**mycmdargs;
	char	**mypaths;
	char	**mysplit;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
int		ft_strcmp(const char *s1, const char *s2);
int		countwords(char **arr);
char	**ft_parse_args(char *av);
char	**buildpath(t_pipex *pipex);
char	*ft_join(char *s1, char *s2);
int		newstrlen(char *envp, char c);
char	**ft_parse_cmds(char **envp);
void	ft_free(char **arg);
int		child_process(char **argv, char **envp, t_pipex pipex, int index);

#endif
