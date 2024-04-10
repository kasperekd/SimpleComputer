#include "myReadkey.h"
int
rk_readkey (enum keys *key)
{
  char buffer[6];

  rk_mytermsave ();
  rk_mytermregime (0, 0, 1, 0, 1);
  rk_mytermrestore ();

  for (int i = 0; i < 6; i++)
    {
      buffer[i] = 0;
    }
  if (read (STDIN_FILENO, buffer, 6) < 0)
    {
      rk_mytermrestore ();
      return -1;
    }

  for (int i = 0; i < 6; i++)
    {
      printf ("%d ", buffer[i]);
    }
  if (strcmp (buffer, "\033[A") == 0)
    {
      *key = KEY_UP;
    }
  else if (strcmp (buffer, "\033[B") == 0)
    {
      *key = KEY_DOWN;
    }
  else if (strcmp (buffer, "\033[D") == 0)
    {
      *key = KEY_LEFT;
    }
  else if (strcmp (buffer, "\033[C") == 0)
    {
      *key = KEY_RIGHT;
    }
  else if (strcmp (buffer, "\033[15~") == 0)
    {
      *key = KEY_F5;
    }
  else if (strcmp (buffer, "\033[17~") == 0)
    {
      *key = KEY_F6;
    }
  else if (strcmp (buffer, "\033") == 0)
    {
      *key = KEY_ESC;
    }
  else if (strcmp (buffer, "\n") == 0)
    {
      *key = KEY_ENTER;
    }
  else if (buffer[0] == 108 && buffer[1] == 0) //l
    {
      *key = KEY_LOAD;
    }
  else if (buffer[0] == 115 && buffer[1] == 0) //s
    {
      *key = KEY_SAVE;
    }
  else if (buffer[0] == 114 && buffer[1] == 0) //r
    {
      *key = KEY_RUN;
    }
  else if (buffer[0] == 116 && buffer[1] == 0) //t
    {
      *key = KEY_STEP;
    }
  else if (buffer[0] == 105 && buffer[1] == 0) //i
    {
      *key = KEY_RESET;
    }
  else
    {
      *key = KEY_UNKNOWN;
    }

  rk_mytermrestore ();
  return 0;
}