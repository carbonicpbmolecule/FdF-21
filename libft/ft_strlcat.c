/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:21:05 by jirwin            #+#    #+#             */
/*   Updated: 2019/09/16 14:21:05 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	rsl;

	i = ft_strlen(dest);
	rsl = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (rsl);
	if (size < i)
		rsl += size;
	else
		rsl += i;
	while (src[j] != '\0' && i < size - 1 && dest != src)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (rsl);
}
