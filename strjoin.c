/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:51:48 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 16:28:43 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	leng(int size, char **strs, char *sep)
{
	int	i;
	int	leng_total;

	i = 0;
	leng_total = 0;
	while (i < size)
	{
		leng_total = leng_total + ft_strlen(strs[i]);
		i++;
	}
	leng_total = leng_total + (ft_strlen(sep) * (size - 1));
	return (leng_total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		leng_total;
	char	*tab;

	if (size == 0)
	{
		tab = malloc(sizeof(char));
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	leng_total = leng(size, strs, sep);
	tab = (char *)malloc(sizeof(char) * (leng_total + 1));
	if (!tab)
		return (tab);
	tab[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < (size - 1))
			ft_strcat(tab, sep);
	}
	return (tab);
}
