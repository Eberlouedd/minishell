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
            ret[i] = 1;
        }
        else if(str[i] == '\"' && !switch_b && !switch_a)
        {
            switch_b = 1;
            ret[i] = 1;
        }
        else if(str[i] == '\'' && switch_a && !switch_b)
        {
            switch_a = 0;
            ret[i] = 1;
        }
        else if(str[i] == '\'' && !switch_a && !switch_b)
        {
            switch_a = 1;
            ret[i] = 1;
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
    char *ret;
    int i;
    int c;
    int j; 

    i = 0;
    c = 0;
    j = 0;
    ret = malloc((ft_strlen(str) + size + 1) * sizeof(int));
    ret[ft_strlen(str) + size] = '\0';
    while(ret[i])
    {
        if (i == tab[c]&& c < size)
        {
            ret[i] = ' ';
            c++;
        }
        else
        {
            ret[i] = str[j];
            j++;
        }
        i++;
    }
    free(str);
    return(ret);
}

char *add_spaces(char *str)
{
	int i;
    int *tab_spaces;
    int *quotes;
    int c;

	i = 1;
    c = 0;
    quotes = create_quote_rep(str);
	while (str[i + 1])
	{
		if((str[i] == '>'
        || str[i] == '<') && str[i+1] != '>' && str[i+1] != '<'
        && quotes[i] != 0
        && str[i - 1] != ' ')
        {
            tab_spaces =  create_add_space(tab_spaces, i, c);
            c++;
            if(str[i + 1] != ' ')
            {
                tab_spaces =  create_add_space(tab_spaces, i + 1, c);
                c++;
            }
        }
        i++;
	}
    if (c > 0)
    {
        str = add_final(str, tab_spaces, c);
        free(tab_spaces);
        free(quotes);
    }
    return(str);
}