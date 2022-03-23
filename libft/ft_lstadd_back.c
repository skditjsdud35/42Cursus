#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
        
	if (lst == NULL || new == NULL)
		return ;
    	if (*lst == NULL)
    	{
		*lst = new_node;
		return ;
    	}
	last = ft_lstlast(*lst);
	new->next = last->next;
	last->next = new;
}
