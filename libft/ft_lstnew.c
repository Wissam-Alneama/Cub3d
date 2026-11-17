/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:50:41 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:48:52 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*alian;

	alian = malloc(sizeof(t_list));
	if (!alian)
		return (NULL);
	alian->content = content;
	alian->next = NULL;
	return (alian);
}
