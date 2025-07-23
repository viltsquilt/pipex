/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/23 16:26:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>                                                               
# include <fcntl.h>                                                               
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct	s_pipex
{
	int		end[2];
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**mycmdargs;
	char	**mypaths;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_parse_args(char *av);
char	*ft_join(char const *s1, char const *s2);
int		newstrlen(char *envp, char c);
int		ft_parse_cmds(char *cmd, char *av, char **envp);
void	ft_pipex(t_pipex pipex, char **argv, char **envp);
void	child1_process(t_pipex pipex, char *cmd, char **argv, char **envp);
void	child2_process(t_pipex pipex, char *cmd, char **argv, char **envp);

#endif
