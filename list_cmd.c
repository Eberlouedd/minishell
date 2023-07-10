#include "minishell.h"

t_commande *create_lstcmd(char *str)
{
	char **div;
	int i;
	int *tab;
    t_commande *c;

	i = 0;
	div = ft_split(str, ' ');
	while(div[i])
		i++;
	tab = malloc(i * sizeof(int));
	create_type_table(div, tab);
    c = ft_lst_newcmd(create_word(div, tab), 0);
    i = 0;
    while(div[i])
    {
        if(tab[i] == 1)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(div[i], 1));
        else if(tab[i] == 2)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(div[i], 2));
        else if(tab[i] == 3)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(div[i], 3));
        else if(tab[i] == 4)
            ft_lstadd_backcmd(&c, ft_lst_newcmd(div[i], 4));
        i++;
    }
    free(tab);
    return(c);
}

t_commande *ft_lst_newcmd(char *cmd, int id)
{
    t_commande *c;
	
	c = malloc(sizeof(t_commande));
	if (!c)
		return (NULL);
	c->cmd= cmd;
    c->id = id;
    c->cmds_split = ft_split(cmd, ' ');
	return (c);
}

char *create_word(char **str, int *tab)
{
    int i;
    char *word;

    word = NULL;
    i = 0;
    while (str[i])
    {
        if(tab[i] == 0)
        {
            word = ft_strjoin(word, str[i]);
            word = ft_strjoin(word, " ");
        }
        i++;
    }
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