/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:48:22 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 17:54:50 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

void scan(char *str, int i, profile **kings, profile **attackers)
{
    char array[4] = {'P','B','R','Q'};
    int k;
    int j;

    j = 0;

    while(str[j])
    {
        k = 0;
		while (k < 4)
        {
            if (str[j] == 'K')
			{
				*kings = create_profile('K', j, i);
//				add_profile(kings, 'K', j, i);
				break ;
			}
            if (str[j] == array[k])
            {
                add_profile(attackers, str[j], j, i);
                break ;
            }
            ++k;
        }
        ++j;
    }
}
