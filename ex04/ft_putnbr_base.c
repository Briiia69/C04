#include <unistd.h>

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
		if ((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a'
				&& base[i] <= 'f'))
			i++;
		else
			return (-1);
	}
	if (i > 16 || i < 2)
		return (-1);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	long_putnbr(long nbr, char *base)
{
	int	base_len;

	base_len = base_check(base);
	if (base_len < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		long_putnbr(nbr * -1, base);
	}
	else
	{
		if (nbr < base_len)
			ft_putchar(base[nbr % base_len]);
		else
		{
			long_putnbr(nbr / base_len, base);
			ft_putchar(base[nbr % base_len]);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = base_check(base);
	if (base_len < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(nbr * -1, base);
	}
	else
	{
		if (nbr < base_len)
			ft_putchar(base[nbr % base_len]);
		else
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putchar(base[nbr % base_len]);
		}
	}
}
