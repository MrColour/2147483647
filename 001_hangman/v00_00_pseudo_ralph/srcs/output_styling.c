/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_styling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:52:56 by kmira             #+#    #+#             */
/*   Updated: 2020/02/13 12:11:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_ralph.h"

char	*color_code(uint8_t red, uint8_t green, uint8_t blue)
{
	char	*result;

	asprintf(&result, "\e[38;2;%d;%d;%dm", red, green, blue);
	return (result);
}

char	*intesity_code(uint8_t intensity)
{
	char	*result;

	result = color_code(intensity, intensity, intensity);
	return (result);
}
