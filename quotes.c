/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/20 17:50:25 by kyacini          ###   ########.fr       */
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
	commande = add_spaces(commande);
	return (commande);
}
