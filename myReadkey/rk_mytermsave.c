#include "myReadkey.h"

int
rk_mytermsave ()
{
  return tcgetattr (STDIN_FILENO, &orig_termios);
}