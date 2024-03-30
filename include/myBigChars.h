#pragma once
#ifndef _MYBIGCHAR_H_
#define _MYBIGCHAR_H_ 1

#include "myTerm.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef _COLORS_
#define _COLORS_ 1
enum colors
{
  BLACK = 0,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
};
#endif

#define CKBOARD ("a")  // ▒
#define HLINE ("q")    // ─
#define VLINE ("x")    // │
#define LUCORNER ("l") // ┌
#define LDCORNER ("m") // └
#define RDCORNER ("j") // ┘
#define RUCORNER ("k") // ┐

int bc_strlen (char *str);
int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int big_char[2], int x, int y, enum colors fg,
                     enum colors bg);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);

#endif