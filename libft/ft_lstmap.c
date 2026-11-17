/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:29:39 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 23:28:00 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*twinlst;
	t_list	*final;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	final = NULL;
	while (lst)
	{
		temp = f(lst->content);
		twinlst = ft_lstnew(temp);
		if (!twinlst)
		{
			del(temp);
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, twinlst);
		lst = lst->next;
	}
	return (final);
}
