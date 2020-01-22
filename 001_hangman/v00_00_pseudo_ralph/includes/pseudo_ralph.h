/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_ralph.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:53:42 by kmira             #+#    #+#             */
/*   Updated: 2020/01/21 22:21:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSEUDO_RALPH_H
# define PSEUDO_RALPH_H

# include <stdio.h>
# include <stdint.h>
# include <string.h>

# define OPTION 0
# define WRONG -1
# define RIGHT  1

# define ANSI_RESET "\033[0m"

char	*color_code(uint8_t red, uint8_t green, uint8_t blue);
char	*intesity_code(uint8_t intensity);

#endif
