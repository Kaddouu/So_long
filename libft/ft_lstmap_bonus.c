/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:00:22 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/17 12:04:49 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		new_element = ft_lstnew(new_content);
		if (!new_element)
		{
			del(new_content);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, new_element);
		lst = lst -> next;
	}
	return (list);
}
