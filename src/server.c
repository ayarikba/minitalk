#include "minitalk.h"

void handle(int signum)
{
    static int i = 0;
    static int j = 0;


        if (signum == SIGUSR1)
            {
                j = j | (1 << i);
                i++;
            }
        else if (signum == SIGUSR2)
            {
                i++;
            } 
    if (i == 8)
    {
        write(1, &j, 1);
        i = 0;
        j = 0;
    }

    return ;
}


int main()
{
    ft_printf("%d\n",getpid());
   /* sigset_t x;
    sigemptyset(&x);
    sigaddset(&x, SIGUSR1);
    sigaddset(&x, SIGUSR2);

    struct sigaction sig;
    sigemptyset(&sig.sa_mask);
    sig.sa_handler = handle;
    sig.sa_flags;

    if (sigaction(SIGUSR1, &sig, NULL) == -1)
        perror("failed");
    
    ft_printf("%d",getpid());
    while (1)*/
    
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
    while(1)
    {
        sleep(1);
    }
    
    return 0;
}