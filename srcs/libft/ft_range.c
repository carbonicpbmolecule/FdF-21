/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:40:29 by jirwin            #+#    #+#             */
/*   Updated: 2019/09/17 19:20:40 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *ofints;

	i = 0;
	if (max <= min)
		return (NULL);
	if (!(ofints = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (i < (max - min))
	{
		ofints[i] = i + min;
		i++;
	}
	return (ofints);
}
