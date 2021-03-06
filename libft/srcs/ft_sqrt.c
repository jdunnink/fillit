/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 18:48:00 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:35:40 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return (0);
}
