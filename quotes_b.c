/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:24:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/22 02:12:22 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char last_quote(char *str)
{
	char c;
	int i;

	while (str[i])
	{
		if(str[i] == '\'')
			c = '\'';
		else if (str[i] == '\"')
			c = '\"';
		i++;
	}
	return (c);
}

int check_unique(char *str)
{
	int i;
	int c;

	while (str[i])
	{
		if(str[i] == '\'')
			c++;
		i++;
	}
	if(c % 2 != 0 && last_quote(str) == '\'')
	{
		printf("non");
		return 0;
	}
	i = 0;
	c = 0;
	while (str[i])
	{
		if(str[i] == '\"')
			c++;
		i++;
	}
	if(c % 2 != 0 && last_quote(str) == '\"')
		return 0;
	return 1;
}

int have_quotes(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\'' || str[i] == '\"')
			return(1);
		i++;
	}
	return(0);
}

char *supp_quotes(char *str)
{
	char *new;
	int i;
	int c;
	int *quotes;


	i = 0;
	c = 0;
	if (!have_quotes(str))
			return(ft_strdup(str));
	quotes = create_quote_rep(str);
	while(i < ft_strlen(str))
	{
		if(quotes[i] == 2)
			c++;
		i++;
	}
	new = malloc(ft_strlen(str) - c + 1);
	new[ft_strlen(str) - c] = '\0';
	i = 0;
	c = 0;
	while(str[i])
	{
		if(quotes[i] != 2)
		{
			new[c] = str[i];
			c++;
		}
		i++;
	}
	free(str);
	free(quotes);
	return(new);
}