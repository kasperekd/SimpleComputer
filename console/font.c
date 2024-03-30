#include <stdio.h>

int
main ()
{
  int ZERO[2] = { 0x3C42C381, 0x81C3423C };
  int ONE[2] = { 0x38781818, 0x1818187E };
  int TWO[2] = { 0x7EC30303, 0x3E60C0FF };
  int THREE[2] = { 0x7E83037E, 0x7E03837E };
  int FOUR[2] = { 0x43C3C3FF, 0x7F030303 };
  int FIVE[2] = { 0xFFC0C0F0, 0x0F0303FF };
  int SIX[2] = { 0x7EC1C0C0, 0xFEC3C37E };
  int SEVEN[2] = { 0xFF03060C, 0x183060C0 };
  int EIGHT[2] = { 0x7E81817E, 0x7E81817E };
  int NINE[2] = { 0x7EC3C37F, 0x0303837E };
  int A[2] = { 0x3C6666C3, 0xFFC3C3C3 };
  int B[2] = { 0xFC8282FC, 0xFC8282FC };
  int C[2] = { 0x7EC1C0C0, 0xC0C0C17E };
  int D[2] = { 0xF0CCC2C1, 0xC1C2CCF0 };
  int E[2] = { 0xFFC0C0C0, 0xFFC0C0FF };
  int F[2] = { 0xFFC0C0C0, 0xFFC0C0C0 };
  int PLUS[2] = { 0x0018187E, 0x7E181800 };
  int MINUS[2] = { 0x0000007E, 0x7E000000 };

  int font[] = { ZERO[0],  ZERO[1],  ONE[0],   ONE[1],   TWO[0],   TWO[1],
                 THREE[0], THREE[1], FOUR[0],  FOUR[1],  FIVE[0],  FIVE[1],
                 SIX[0],   SIX[1],   SEVEN[0], SEVEN[1], EIGHT[0], EIGHT[1],
                 NINE[0],  NINE[1],  A[0],     A[1],     B[0],     B[1],
                 C[0],     C[1],     D[0],     D[1],     E[0],     E[1],
                 F[0],     F[1],     PLUS[0],  PLUS[1],  MINUS[0], MINUS[1] };

  FILE *file = fopen ("font.dat", "wb");

  if (file != NULL)
    {
      fwrite (font, sizeof (int), sizeof (font) / sizeof (int), file);
      fclose (file);
      printf ("Font data has been written to font.dat\n");
    }
  else
    {
      printf ("Error opening file.\n");
    }

  return 0;

  return 0;
}