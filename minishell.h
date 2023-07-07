/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:47 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/07 20:12:06 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"


typedef struct s_heredoc
{
	char	*filename;
	char	*file;
}	t_heredoc;

typedef s_commande{
	char *cmd;
	char		**cmds_split;
	int			id;
	t_heredoc	*hd;
	t_command	*next;
}	t_commande;

struct s_partition
{
	t_command	*cmds;
	int			pid;
	t_partition	*next;
};

t_list *initialized_env(char **env);

#endif