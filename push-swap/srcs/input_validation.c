#include "push_swap.h"

static int      num_check(char *argv);
static int      check_int(char *argv);
static int      duplicate_detected(char *argv, char **av, int i);
static int      invalid_input(int error);

int check_input(char **argv)
{
    int i;

    i = 0;
    while(argv[++i])
    {
        if (num_check(argv[i]) != 0)
        {
            return (invalid_input(1));
        }
        if (check_int(argv[i]) != 0)
        {
            return (invalid_input(2));
        }
        if (duplicate_detected(argv[i], argv, i) != 0)
        {
            return (invalid_input(3));
        }
    }
    return (0);
}

static int num_check(char *argv)
{
    int i;

    i = -1;
    while (argv[++i])
    {
        if (argv[i] == '-')
            i++;
        if (!(argv[i] >= '0' && argv[i] <= '9'))
            return (-1);
    }
    return (0);
}

static int check_int(char *argv)
{
    long int num;

    num = ft_atoi(argv);
    if (num < INT_MIN || num > INT_MAX)
        return (-1);
    return (0);
}

static int duplicate_detected(char *argv, char **av, int i)
{
    long int num;

    num = ft_atoi(argv);
    while (av[i++])
    {
        if (num == ft_atoi(av[i++]))
            return (-1);
        i++;
    }
    return (0);
}

static int invalid_input(int error)
{
    if (error == 1 || error == 2 || error == 3)
    {
        write(1, "Error\n", 6);
        exit(1);
    }
    return (-1);
}