/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:13:41 by jirwin            #+#    #+#             */
/*   Updated: 2019/09/19 13:34:33 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	if (alst)
	{
		lst = *alst;
		while (lst)
		{
			nxtlst = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		*alst = NULL;
	}
}
