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
  else if (strcmp (buffer, "\033") == 0)
    { 
      *key = KEY_ESC;
    }
  else if (strcmp (buffer, "\n") == 0)
    {
      *key = KEY_ENTER;
    }
  else if (buffer[0]==27 && buffer[1]== 91 && buffer[2]== 49 && buffer[3]== 53 && buffer[4]== 126)
    { 
      *key = KEY_F5;
    }
  // else if (strcmp (buffer, "\x1b[15~") == 0)
  //   { 
  //     *key = KEY_F5;
  //   }
  else if (buffer[0]==27 && buffer[1]== 91 && buffer[2]== 49 && buffer[3]== 55 && buffer[4]== 126)
    { 
      *key = KEY_F6;
    }
  else
    {
      *key = KEY_UNKNOWN;
    }

  rk_mytermrestore ();
  return 0;
}