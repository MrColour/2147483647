/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrase_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:16:20 by xinu              #+#    #+#             */
/*   Updated: 2020/02/13 12:11:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_ralph.h"


void	update_phrase_state(char *phrase, char *phrase_state, char guess)
{
	int		i;

	i = 0;
	while (phrase[i] != '\0')
	{
		if (phrase[i] == guess)
			phrase_state[i] = guess;
		i++;
	}
}

int		phase_guessed(char *phrase_state)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (phrase_state[i] != '\0')
	{
		if (phrase_state[i] == '_')
		{
			result = 0;
			break;
		}
		i++;
	}
	return (result);
}
