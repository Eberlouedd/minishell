/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:24:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/11 13:41:02 by kyacini          ###   ########.fr       */
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