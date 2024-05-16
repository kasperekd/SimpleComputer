#include "CU.h"

int
CPUINFO ()
{
  mt_gotoXY (1, 26);
  printf ("                                                       "
          "                                                       ");
  mt_gotoXY (1, 26);
  printf ("Oshlakov Konstantin Konstantinovich IA-232");

  return 0;
}

int
READ (int operand)
{
  drawFrame (operand);
  mt_gotoXY (1, 26);
  printf ("                                                       "
          "                                                       ");
  mt_gotoXY (1, 26);
  printf ("INPUT > ");
  int value;
  rk_readvalue (&value, 0);

  if (value < 0x0 || value > 0xffff)
    {
      sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 1);
      return -1;
    }

  sc_memorySet (operand, value);
  printTerm (operand, 0);

  mt_gotoXY (1, 26);
  printf ("                                                       "
          "                                                       ");

  return 0;
}

int
WRITE (int operand)
{
  printTerm (operand, 1);
  return 0;
}

int
LOAD (int operand)
{
  int val;
  mc_controllerread (operand, &val);
  sc_accumulatorSet (val);

  // sc_memoryGet (operand, &val);
  drawFrame (operand);
  // sc_accumulatorSet (val);
  return 0;
}

int
STORE (int operand)
{
  int val;
  sc_accumulatorGet (&val);
  drawFrame (operand);
  mc_controllerwrite (operand, val);
  // sc_memorySet (operand, val);
  return 0;
}

int
JUMP (int operand)
{
  sc_icounterSet (operand - 1);

  // drawFrame(operand);
  // raise (SIGALRM);//CU();
  return 0;
}

int
JNEG (int operand)
{
  int val;
  sc_accumulatorGet (&val);

  int sign, command, _operand;
  sc_commandDecode (val, &sign, &command, &_operand);
  if (sign == 0)
    {
      sc_icounterSet (operand - 1);
      // drawFrame(operand);
      // raise (SIGALRM);//CU();
    }
  return 0;
}

int
JZ (int operand)
{
  int val;
  sc_accumulatorGet (&val);

  int sign, command, _operand;
  sc_commandDecode (val, &sign, &command, &_operand);

  int normalValue = (command << 8) ^ _operand;
  if (normalValue == 0)
    {
      sc_icounterSet (operand - 1);
      // drawFrame(operand);
      // raise (SIGALRM);//CU();
    }
  return 0;
}

int
HALT ()
{
  sc_regSet (REG_IMPULSE_IGNORE, 1);
  return 0;
}

void
CU ()
{
  int icount;
  if (sc_icounterGet (&icount) < 0)
    {
      sc_regSet (REG_IMPULSE_IGNORE, 1);
      return;
    }

  int memory_get, value_c = 0;
  mc_controllerread (icount, &value_c);

  // int value = 0;
  // if (sc_memoryGet (icount, &value) < 0)
  //   {
  //     sc_regSet (REG_MEMORY_OUT_OF_BOUNDS, 1);
  //     return;
  //   }

  int sign, command, operand;
  if (sc_commandDecode (value_c, &sign, &command, &operand) < 0)
    {
      sc_regSet (REG_IMPULSE_IGNORE, 1);
      sc_regSet (REG_INVALID_COMMAND, 1);
      return;
    }

  if (sign == 1)
    {
      sc_regSet (REG_IMPULSE_IGNORE, 1);
      sc_regSet (REG_INVALID_COMMAND, 1);
      return;
    }

  if (((command >= 0x1E) && (command <= 0x21))
      || ((command >= 0x33) && (command <= 0x36)))
    {
      ALU (command, operand);
    }
  else
    {
      switch (command)
        {
        case 0x00:
          break;
        case 0x01:
          CPUINFO ();
          break;
        case 0x0A:
          READ (operand);
          break;
        case 0x0B:
          WRITE (operand);
          break;
        case 0x14:
          LOAD (operand);
          break;
        case 0x15:
          // mc_controllerwrite (operand, accumulator);
          STORE (operand);
          break;
        case 0x28:
          JUMP (operand);
          break;
        case 0x29:
          JNEG (operand);
          break;
        case 0x2A:
          JZ (operand);
          break;
        case 0x2B:
          HALT ();
          break;
        }
    }
  // printTerm(icount, 0);
}