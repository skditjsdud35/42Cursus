#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
        *lst = curr;
	}
	*lst = 0;
}
