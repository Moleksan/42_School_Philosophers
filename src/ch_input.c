#include "philosophers.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int is_positive_integer(const char *str)
{
    if (!str || *str == '\0')
        return (0);
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int check_input(int ac, char **av)
{
    int is_valid = 1;
    int i = -1;
    int max_args;
    const char *error_messages[] = {
        "Error: Incorrect number of arguments.\nExpected 4 or 5 arguments.\n",
        "Error: [number_of_philosophers]: This should be a positive integer representing the number of philosophers (> 0).\n",
        "Error: [time_to_die]: This should be a positive integer. It represents the time in milliseconds after which a philosopher dies if they don't start eating.\n",
        "Error: [time_to_eat]: This should be a positive integer. It represents the time in milliseconds that a philosopher spends eating.\n",
        "Error: [time_to_sleep]: This should be a positive integer. It represents the time in milliseconds that a philosopher spends sleeping.\n",
        "Error: [number_of_meals] (optional): If provided, it should be a positive integer specifying the minimum number of meals each philosopher must eat.\n"
    };
    if (ac != 5 && ac != 6)
    {
        printf("%s", error_messages[0]);
        print_error("Usage:\n");
        print_error("  ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals (optional)]\n\n");
        is_valid = 0;
    }
    if (ac == 6)
    {
        max_args = 5;
    }
    else
    {
        max_args = 4;
    }
    while (++i < max_args)
    {
        if (!is_positive_integer(av[i + 1]) || ft_atoi(av[i + 1]) <= 0)
        {
            printf("%s", error_messages[i + 1]);
            is_valid = 0;
        }
    }
    return (is_valid);
}

void	print_error(char *str)
{
	printf("%s", str);
}

