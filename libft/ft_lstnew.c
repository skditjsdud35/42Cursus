#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (!nlst)
		return (0);
	nlst->content = content;
	nlst->next = 0;
	return (nlst);
}
