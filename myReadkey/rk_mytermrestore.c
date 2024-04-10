#include "myReadkey.h"

int
rk_mytermrestore (void)
{
    return tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}