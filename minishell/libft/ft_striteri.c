/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:55:21 by dameneze          #+#    #+#             */
/*   Updated: 2022/11/19 19:07:34 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*   Applies the function ’f’ on each character of
*   the string passed as argument, passing its index
*   as first argument. Each character is passed by
*   address to ’f’ to be modified if necessary.
*	PARAMETERS
*	#1 - The string on which to iterate.
*	#2 - The function to apply to each character.
*	RETURN VALUES
*	None.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			(*f)(i, &s[i]);
	}
}
