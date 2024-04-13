#include "myReadkey.h"

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  new_termios = orig_termios;

  if (regime == 1)
    new_termios.c_lflag |= ICANON;
  else if (regime == 0)
    new_termios.c_lflag &= ~ICANON;
  else
    return -1;
  if (regime == 0)
    {
      new_termios.c_cc[VTIME] = vtime;
      new_termios.c_cc[VMIN] = vmin;
      if (echo == 1)
        new_termios.c_lflag |= ECHO;
      else if (echo == 0)
        new_termios.c_lflag &= ~ECHO;
      else
        return -1;
      if (sigint == 1)
        new_termios.c_lflag |= ISIG;
      else if (sigint == 0)
        new_termios.c_lflag &= ~ISIG;
      else
        return -1;
    }
  return 1;
}