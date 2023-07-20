#include "minishell.h"

t_partition *create_partition(char **partitions)
{
    t_partition *part;
    int i;

    i = 1;
    part = ft_lstnew_partition(partitions[0]);
    while (partitions[i])
    {
        ft_lstadd_back_partition(&part, ft_lstnew_partition(partitions[i]));
        i++;
    }
    return (part);
}

t_partition *parsing(char *line)
{
    char **partitions;
    t_partition *part;

    if(!ft_strcmp(line, ""))
        return (NULL);
    partitions = ft_split(line, '|');
    part = create_partition(partitions);
    return (part);
}