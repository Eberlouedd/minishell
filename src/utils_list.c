/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:23:07 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/31 06:18:24 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_partition	*ft_lstnew_partition(char *part)
{
	t_partition	*liste;
    t_commande *c;
	
	liste = malloc(sizeof(t_list));
    c = create_lstcmd(part);
	if (!liste || !c)
		return (NULL);
	liste->cmds = c;
	liste->next = NULL;
	return (liste);
}

t_partition	*ft_lstlast_partition(t_partition *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_partition(t_partition **lst, t_partition *new)
{
	t_partition	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_partition(*lst);
	last->next = new;
}
