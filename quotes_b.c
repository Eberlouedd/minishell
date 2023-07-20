/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:24:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/20 06:01:15 by skhali           ###   ########.fr       */
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
		return 0;
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

char *supp_quotes(char *str)
{
	char *new;
	int i;
	int c;

	i = 1;
	c = 0;
	if (str[ft_strlen(str) - 1] != '\'' && str[ft_strlen(str) - 1] != '\"')
			return(str);
	new = malloc(ft_strlen(str) - 1);
	new[ft_strlen(str) - 2] = '\0';
	while(str[i + 1])
	{
		new[c] = str[i];
		c++;
		i++;
	}
	free(str);
	return(new);
}