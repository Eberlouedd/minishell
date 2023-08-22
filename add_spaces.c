/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:22:37 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/22 01:48:49 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int *create_quote_rep(char *str)
{
    int *ret;
    int i;
    int switch_b;
    int switch_a;

    i = 0;
    switch_b = 0;
    switch_a = 0;
    ret = malloc(ft_strlen(str) * sizeof(int));
    while (str[i])
    {
        if(str[i] == '\"' && switch_b && !switch_a)
        {
            switch_b = 0;
            ret[i] = 3;
        }
        else if(str[i] == '\"' && !switch_b && !switch_a)
        {
            switch_b = 1;
            ret[i] = 3;
        }
        else if(str[i] == '\'' && switch_a && !switch_b)
        {
            switch_a = 0;
            ret[i] = 2;
        }
        else if(str[i] == '\'' && !switch_a && !switch_b)
        {
            switch_a = 1;
            ret[i] = 2;
        }
        else if(switch_a || switch_b)
            ret[i] = 0;
        else 
            ret[i] = 1;
        i++;
    }
    return(ret);
}

int *create_add_space(int *tab, int position, int size)
{
    int *ret;
    int i;

    i = 0;
    ret = malloc((size + 1) * sizeof(int));
    while (i < size)
    {
        ret[i] = tab[i];
        i++;
    }
    ret[i] = position;
    free(tab);
    return (ret);
}

char *add_final(char *str, int *tab, int size)
{
    char *new;
    int i;
    int j; 

    i = 0;
    j = 0;
    new = malloc((size + 1) * sizeof(int));
    new[size] = '\0';
    while(i < size)
    {
        if (tab[i] == 1)
            new[i] = ' ';
        else
        {
            new[i] = str[j];
            j++;
        }
        i++;
    }
    free(str);
    return(new);
}

char *add_spaces(char *str)
{
	int i;
    int *tab_spaces;
    int *quotes;
    int c;

	i = 0;
    c = 0;
    quotes = create_quote_rep(str);
    tab_spaces = malloc(1 * sizeof(int));
    tab_spaces[0] = 0;
	while (str[i])
	{
		if((str[i] == '>'
        || str[i] == '<') && str[i+1] != '>' && str[i+1] != '<'
        && quotes[i] != 0
        && str[i + 1] != ' '
        || ((str[i + 1] == '>' || str[i + 1] == '<') && str[i] != '>'
        && str[i] != '<' && str[i] != ' ' && quotes[i + 1] != 0))
        {
            tab_spaces = create_add_space(tab_spaces, 0, c);
            c++;
            tab_spaces = create_add_space(tab_spaces, 1, c);
        }
        else
            tab_spaces = create_add_space(tab_spaces, 0, c);
        i++;
        c++;
	}
    if (c > 0)
    {
        str = add_final(str, tab_spaces, c);
        free(tab_spaces);
        free(quotes);
    }
    return(ft_strdup(str));
}