#include "minitalk.h"

static void err(void)
{
    ft_printf("error occurred!!!!\n");
    exit(EXIT_FAILURE);
}
static int controller (char *av)
{
    int i;
    
    i = -1;
    while (av[++i])
        if (av[i] < '0' || av[i] > '9')
            return (1);
    
    return (0);
}

static void send_str(char *pid, char *str)
{
    int p;
    int i;
    int j;

    i = 0;
    p = ft_atoi(pid);
    while(str[i])
    {
        j = 0;
        while (j < 8)
        {
            if ((str[i] >> j) & 1)
                kill(p, SIGUSR1) ;
            else 
                kill(p, SIGUSR2)    ;

            j++;
          //  pause();
            usleep(100);
        }
        i++;
        usleep(50);
    }   
    return ;
}

int main (int ac, char **av)
{
    if (ac != 3 || controller(av[1]))
        return (0);
    
    send_str(av[1], av[2]);
    return (0);
}