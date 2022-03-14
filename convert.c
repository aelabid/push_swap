/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:03:15 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/11 20:14:51 by aelabid          ###   ########.fr       */
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
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (ft_strlen(s) <= start)
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


static int	ft_gettheworld(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_numofsplit(const char *s, char spl)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == spl)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != spl)
			i++;
	}
	return (k);
}

static void	ft_inits(int *i, int *k)
{
	*i = -1;
	*k = -1;
}

static void	ft_free(char **spl)
{
	int	j;

	j = -1;
	while (spl[++j])
		free(spl[j]);
	free(spl);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**spl;
	int		k;

	ft_inits(&i, &k);
	if (!s)
		return (NULL);
	spl = malloc((ft_numofsplit(s, c) + 1) * sizeof(char *));
	if (spl == 0)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			spl[++k] = ft_substr(s, i, ft_gettheworld(s + i, c));
			if (!spl[k])
			{
				ft_free(spl);
				return (NULL);
			}
			i = i + ft_gettheworld(s + i, c) - 1;
		}
	}
	spl[++k] = NULL;
	return (spl);
}

char	**convert(int *ac, char **av)
{
	char	*str;
	char	**str2;

	str = ft_strjoin(*ac, av, " ");
	*ac = ft_numofsplit(str, ' ');
	str2 = ft_split(str, ' ');
	return (str2);
}