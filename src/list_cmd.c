/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:22:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/31 06:18:05 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_commande *create_lstcmd(char *str)
{
	char **div;
	int i;
	int *tab;
    t_commande *c;

	i = 0;
	div = ft_split(str, ' ');
    clean_del(div);
	while(div[i])
		i++;
	tab = malloc(i * sizeof(int));
	create_type_table(div, tab);
    c = ft_lst_newcmd(create_word(div, tab), 0);
    i = 0;
    while(div[i])
    {
        if(tab[i] == 1)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(supp_quotes(div[i]), 1));
        else if(tab[i] == 2)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(supp_quotes(div[i]), 2));
        else if(tab[i] == 3)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(supp_quotes(div[i]), 3));
        else if(tab[i] == 4)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(supp_quotes(div[i]), 4));
        i++;
    }
    free(div);
    free(tab);
    return(c);
}

t_commande *ft_lst_newcmd(char *cmd, int id)
{
    t_commande *c;

	c = malloc(sizeof(t_commande));
	if (!c || !cmd)
		return (NULL);
    c->cmd = cmd;
    c->id = id;
    c->cmds_split = ft_split(cmd, ' ');
    c->next = NULL;
	return (c);
}

char *create_word(char **str, int *tab)
{
    int i;
    char *word;
    char *buff;
    
    word = NULL;
    i = 0;
    while (str[i])
    {
        if(tab[i] == 0)
        {
            buff = supp_quotes(str[i]);
            word = ft_strjoin(word, buff);
            free(buff);
            word = ft_strjoin(word, " ");
        }
        i++;
    }
    if (word)
        word = ft_substr(word, 0, ft_strlen(word) - 1);
    return(word);
}

void	ft_lstadd_backcmd(t_commande **lst, t_commande *new)
{
	t_commande	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlastcmd(*lst);
	last->next = new;
}

t_commande	*ft_lstlastcmd(t_commande *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}