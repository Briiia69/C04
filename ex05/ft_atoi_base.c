/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:19:36 by alnoukan          #+#    #+#             */
/*   Updated: 2026/06/30 12:35:17 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_multiple(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[i] && base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base_check(char *base)
{
	int	i;

	if (check_multiple(base))
		return (-1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9
				&& base[i] <= 13))
			return (-1);
		i++;
	}
	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (-1);
	return (i);
}

void	check_base_char(int *value, char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			*value = i;
			return ;
		}
		i++;
	}
	*value = -1;
}

int	get_sign(int *i, char *str)
{
	int	sign;

	sign = 1;
	while (str[*i] && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			sign *= -1;
		*i = *i + 1;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	res;
	int			sign;
	int			i;
	int			value;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = get_sign(&i, str);
	value = 0;
	while (str[i])
	{
		check_base_char(&value, str[i], base);
		if (value < 0)
			break ;
		res = res * base_check(base) + value;
		i++;
	}
	return ((int)(res * sign));
}
