/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:14 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:17:14 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp_lst;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{	
		tmp_lst = ft_lstnew(f(lst->content));
		if (!tmp_lst)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&new_list, tmp_lst);
		}
		lst = lst->next;
	}
	return (new_list);
}
