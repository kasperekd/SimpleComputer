#include "mySimpleComputer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXPECTED_ADDRESS_OF_MEMORY_CELL -1
#define ERR_WRONG_COMMAND -2
#define ERR_WRONG_OPERAND -3
#define ERR_BY_ENCODE -4

#define READ 0x0A
#define WRITE 0x0B
#define LOAD 0x14
#define STORE 0x15
#define ADD 0x1E
#define SUB 0x1F
#define DIVIDE 0x20
#define MUL 0x21
#define JUMP 0x28
#define JNEG 0x29
#define JZ 0x2A
#define HALT 0x2B
#define NOT 0x33
#define AND 0x34
#define OR 0x35

FILE *input = NULL;

void
load_file (const char *filename)
{
  if ((input = fopen (filename, "r")) == NULL)
    {
      fprintf (stderr, "Can't open file: no such file. (%s)\n", filename);
      exit (EXIT_FAILURE);
    }
  return;
}

void
translation (const char *filename)
{
  for (int i = 0; !feof (input); i++)
    {
      char line[255];
      if (!fgets (line, 255, input))
        {
          if (feof (input))
            {
              break;
            }
          else
            {
              fprintf (stderr, "Line %d: can't read line from file.\n", i++);
              break;
            }
        }
      char *addr;
      char *command;
      char *oper;
      int num_of_cmd = 0;
      int operand = 0;
      int address = 0;

      char *ptr = strtok (line, " ");
      addr = ptr;

      ptr = strtok (NULL, " ");
      command = ptr;

      ptr = strtok (NULL, " +");
      oper = ptr;
      address = atoi (addr);
      // address = strtol(addr, NULL, 16);

      ptr = strtok (NULL, " ");

      if (ptr != NULL && ptr[0] != ';')
        {
          fprintf (stderr, "Line %d: unexpected symbols.\n", ++i);
          break;
        }

      if (!atoi (addr) && strcmp (addr, "00") != 0)
        {
          fprintf (stderr, "Line %d: expected address of memory cell.\n", ++i);
          break;
        }
      //!!!
      //   operand = atoi (oper);
      operand = strtol (oper, NULL, 16);
      char buffer[255];
      sprintf (buffer, "%d", operand);
      sscanf (buffer, "%d", &operand);
      if ((operand == NULL
           && (strcmp (command, "HALT") < 0
               || (strcmp (oper, "0\n") != 0 && strcmp (oper, "00\n") != 0
                   && strcmp (oper, "000\n") != 0
                   && strcmp (oper, "0000\n") != 0))))
        {
          if ((strcmp (command, "=") != 0))
            {
              fprintf (stderr, "Line %d: wrong operand.\n", ++i);
              exit (EXIT_FAILURE);
            }
        }

      if (!strcmp (command, "READ"))
        {
          num_of_cmd = READ;
        }
      else if (!strcmp (command, "WRITE"))
        {
          num_of_cmd = WRITE;
        }
      else if (!strcmp (command, "LOAD"))
        {
          num_of_cmd = LOAD;
        }
      else if (!strcmp (command, "STORE"))
        {
          num_of_cmd = STORE;
        }
      else if (!strcmp (command, "ADD"))
        {
          num_of_cmd = ADD;
        }
      else if (!strcmp (command, "SUB"))
        {
          num_of_cmd = SUB;
        }
      else if (!strcmp (command, "DIVIDE"))
        {
          num_of_cmd = DIVIDE;
        }
      else if (!strcmp (command, "MUL"))
        {
          num_of_cmd = MUL;
        }
      else if (!strcmp (command, "JUMP"))
        {
          num_of_cmd = JUMP;
        }
      else if (!strcmp (command, "JNEG"))
        {
          num_of_cmd = JNEG;
        }
      else if (!strcmp (command, "JZ"))
        {
          num_of_cmd = JZ;
        }
      else if (!strcmp (command, "HALT"))
        {
          num_of_cmd = HALT;
        }
      else if (!strcmp (command, "AND"))
        {
          num_of_cmd = AND;
        }
      else if (!strcmp (command, "OR"))
        {
          num_of_cmd = OR;
        }
      else if (command[0] == '=')
        {
          sscanf (oper, "%d", &operand);
          sc_memorySet (address, operand);
          continue;
        }
      else
        {
          fprintf (stderr, "Line %d: wrong command.\n", ++i);
          break;
        }

      int value = 0;
      if (sc_commandEncode (0, num_of_cmd, operand, &value) < 0)
        {
          fprintf (stderr,
                   "Line %d: error by encode. Check command or operand.\n",
                   ++i);
          break;
        }
      sc_memorySet (address, value);
    }
  // sc_regSet(1,1);
  // sc_regSet(FLAG_IGNOR_PULS,1);
  sc_memorySave (strdup (filename));
}

int
main (int argc, const char **argv)
{
  if (argc < 3)
    {
      fprintf (stderr, "Usage: %s input.sa output.o\n", argv[0]);
      exit (EXIT_FAILURE);
    }
  sc_memoryInit ();
  load_file (argv[1]);
  translation (argv[2]);
  return 0;
}