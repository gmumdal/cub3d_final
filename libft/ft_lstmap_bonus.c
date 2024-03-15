/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:30:34 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/11 16:34:17 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ret_lst;
	void	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret_lst = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new_lst = ft_lstnew(tmp);
		if (new_lst == NULL)
		{
			ft_lstclear(&ret_lst, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&ret_lst, new_lst);
		lst = lst->next;
	}
	return (ret_lst);
}
