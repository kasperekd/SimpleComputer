#include "IRC.h"

void setSignals()
{
    signal(SIGALRM, IRC);
    signal(SIGUSR1, IRC);
}

void IRC(int signum)
{
    if (signum == SIGALRM)
    {
        CU();
        
        int ignore;
        sc_regGet(REG_IMPULSE_IGNORE, &ignore);
        
        int ic;
        sc_icounterGet(&ic);
            drawFrame(ic);
        
        if (!ignore && ic < 99 && ic >= 0)
        {
            sc_icounterSet(++ic);
        }
        else if (ic >= 99)
        {
            sc_icounterSet(0);
        }
        
        if (!ignore)
        {
            struct itimerval timer;
            timer.it_value.tv_sec = 0;
            timer.it_value.tv_usec = 500000; // 0.5 секунд в микросекундах
            timer.it_interval.tv_sec = 0;
            timer.it_interval.tv_usec = 0;

            setitimer(ITIMER_REAL, &timer, NULL);
        }
        
    }
    else if (signum == SIGUSR1)
    {
        alarm(0);
        sc_accumulatorSet(0);
        sc_icounterSet(0);
        sc_regSet(REG_IMPULSE_IGNORE, 1);
    }
}

