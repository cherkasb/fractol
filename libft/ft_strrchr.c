/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:20:05 by bcherkas          #+#    #+#             */
/*   Updated: 2017/11/13 18:43:29 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*k;

	k = NULL;
	while (*s)
	{
		if (*s == c)
			k = (char *)s;
		s++;
	}
	if (c == 0)
		k = (char *)s;
	return (k);
}
