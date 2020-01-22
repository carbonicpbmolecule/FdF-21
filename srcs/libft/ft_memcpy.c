/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:05:13 by jirwin            #+#    #+#             */
/*   Updated: 2019/09/17 17:51:09 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst && src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
	}
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
