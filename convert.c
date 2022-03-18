/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:03:15 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/18 16:28:19 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nstr;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen2(s))
		len = ft_strlen2(s);
	if (ft_strlen2(s) <= start)
		return (ft_strdup(""));
	nstr = malloc((len + 1) * sizeof(char));
	if (nstr == 0)
		return (0);
	while (i < len && s[i] != '\0')
	{
		nstr[i] = s[start];
		i++;
		start++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	**convert(int *ac, char **av)
{
	char	*str;
	char	**str2;

	str = ft_strjoin(*ac, av, " ");
	*ac = ft_numofsplit(str, ' ');
	str2 = ft_split(str, ' ');
	free(str);
	return (str2);
}
