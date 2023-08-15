/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:47 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/15 18:20:34 by kyacini          ###   ########.fr       */
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
# define WORD 0;
# define R_DIR 1;
# define L_DIR 2;
# define RD_DIR 3;
# define LD_DIR 4;

typedef struct s_heredoc
{
	char	*filename;
	char	*file;
}	t_heredoc;

typedef struct s_commande{
	char 		*cmd;
	char		**cmds_split;
	int			id;
	t_heredoc	*hd;
	struct s_commande	*next;
}	t_commande;

typedef struct s_partition
{
	t_commande	*cmds;
	int			pid;
	struct s_partition	*next;
}	t_partition;

t_list *initialized_env(char **env);
void	free_double_char(char	**str);
t_partition	*ft_lstnew_partition(char *cmd);
void	ft_lstadd_back_partition(t_partition **lst, t_partition *new);
t_partition	*ft_lstlast_partition(t_partition *lst);
t_partition *create_partition(char **partitions);
t_partition *parsing(char *line);
t_commande *create_lstcmd(char *str);
t_commande *ft_lst_newcmd(char *cmd, int id);
void	ft_lstadd_backcmd(t_commande **lst, t_commande *new);
t_commande	*ft_lstlastcmd(t_commande *lst);
char *create_word(char **str, int *tab);
int *create_type_table(char **div, int *tab);
int check_unique(char *str);
char	*first_transformation(char *commande, t_list *var_env);
int *create_quote_rep(char *str);
char *add_spaces(char *str);
char *supp_quotes(char *str);
int	afflistc(t_commande *var_env);
void clean_del(char **str);
char *illuminate_variables(char *str, t_list *var_env);

#endif