/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:48 by dexposit          #+#    #+#             */
/*   Updated: 2022/01/28 17:30:06 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (!word && *s != c)
		{
			word = 1;
			count++;
		}
		if (word && *s == c)
			word = 0;
		s++;
	}
	return (count);
}
	/*
	 * 	x	->	inicio de nuestro string con palabras y delimitadores
	 *	**ptr	->	puntero2 que apunta a un puntero1 y este a su vez a x
	 *		*ptr	->	donde apunta puntero2 (puntero1) modificarias a donde ptr doble va 
	 *		**ptr	->	donde apunta puntero1 (x) modificas a donde apunta el ptr simple
	 * */
	/*
	 *	Mover str hasta inicio de una palabra
	 *	Apuntar la cadena aux al fin de esta palabra con strchr
	 *	Usar substr con la diferencia de str y aux
	*/

static void	save_word(char	**dst, char	**str, char c)
{
	char	*aux;

	while (**str == c)
		*str = *str + 1;
	aux = ft_strchr(*str, c);
	if (aux == 0)
		aux = *str + 1 + ft_strlen(*str);
	*dst = ft_substr(*str, 0, aux - *str);
	while ((aux - *str) != 0)
		*str = *str + 1;
}
	/*	1-Contar palabras
	 *	2-Copia del string no constante para trabajar con el
	 *	3-Reservar memoria para el doble ptr donde guardar palabras
	 *	4-LLamar a la función de meter palabras hasta que esten todas
	 *	5-Control de fallos en reserva de memoria
	 *	6-Devolver el string de palabras
	 *	*/

char	**ft_split(char const *s, char c)
{
	char	*str;
	size_t	nw;
	char	**res;
	size_t	i;

	nw = count_words(s, c);
	str = (char *)s;
	res = malloc(sizeof(char *) * (nw + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < nw)
	{
		save_word(&(res[i]), &str, c);
		if (res[i] == 0)
		{
			while (i-- >= 0)
				free(res[i]);
			free(res);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
int main(void)
{
	char *ptr = "aaa  aaa     ";
	printf("%zu\n", count_words(ptr, ' '));
	
	ptr = " hola l mundo";
	printf("%zu\n", count_words(ptr, ' '));
	char **str = ft_split(ptr, ' ');
	int i = 0;
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
	i = 0;
			while (str[i])
			{
				free(str[i]);
				i++;
			}
			free(str);
	return (0);
}*/
