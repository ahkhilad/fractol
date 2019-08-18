/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:16:41 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/07/03 15:05:37 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_mkstr(const char *str, char c, char **ptr)
{
	size_t count;
	size_t i;
	size_t j;

	count = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			count++;
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			if (!(ptr[j] = (char *)malloc(sizeof(char) * count + 1)))
				return ;
			j++;
			count = 0;
		}
		i++;
	}
	ptr[j] = NULL;
}

static void		ft_fill(const char *str, char c, char **ptr)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			ptr[j][count++] = str[i];
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			ptr[j][count] = '\0';
			j++;
			count = 0;
		}
		i++;
	}
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	count;
	char	**ptr;

	if (s)
	{
		count = 0;
		ptr = NULL;
		if (!(ptr = malloc(sizeof(char *) * ((ft_words_counter(s, c)) + 1))))
			return (0);
		ft_mkstr(s, c, ptr);
		ft_fill(s, c, ptr);
		return (ptr);
	}
	return (NULL);
}
