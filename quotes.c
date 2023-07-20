/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/20 04:49:43 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char last_character(char *str)
{
	int c;
	int i;

	while (str[i])
	{
		if(str[i] != ' ')
			c = i;
		i++;
	}
	return (str[c]);
}

int test_quotes(char *str)
{
	int i;
	int c;
	int j;

	i = 0;
	c = 0;
	j = 0;
	while(str[i])
	{
		if(str[i] == '\'')
			c++;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == '\"')
			j++;
		i++;
	}
	if (c % 2 != 0 && j % 2 != 0)
		return (0);
	return (1);
}

int *double_quote_gestion(char *str)
{
	int *tab_double_quote;
	int c;
	int i;

	i = 0;
	c = 0;
	while (str[i])
	{
		if(str[i] == '\"')
			c++;
		i++;
	}
	tab_double_quote = malloc(c * sizeof(int));
	i = 0;
	c = 0;
	while (str[i])
	{
		if(str[i] == '\"')
		{
			tab_double_quote[c] = i;
			c++;
		}
	}
	return (tab_double_quote);
}

int *single_quote_gestion(char *str)
{
	int *tab_single_quote;
	int c;
	int i;

	i = 0;
	c = 0;
	while (str[i])
	{
		if(str[i] == '\"')
			c++;
		i++;
	}
	tab_single_quote = malloc(c * sizeof(int));
	i = 0;
	c = 0;
	while (str[i])
	{
		if(str[i] == '\"')
		{
			tab_single_quote[c] = i;
			c++;
		}
	}
	return (tab_single_quote);
}

char	*first_transformation(char *commande)
{
	char *new;
	int i;
	
	i = 0;
	if(ft_strcmp(commande,"") == 0)
		return "";
	if (last_character(commande) == '>'
		|| last_character(commande) == '<'
		|| !test_quotes(commande)
		|| !check_unique(commande))
	{
		free(commande);
		printf("error\n");
		return("");
	}
	commande = add_spaces(commande, create_quote_rep(commande));
	return (commande);
}
