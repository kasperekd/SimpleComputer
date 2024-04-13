#pragma once
#ifndef _READKEY_H
#define _READKEY_H
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios, new_termios;

enum keys
{
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_ENTER,
  KEY_ESC,
  KEY_F5,
  KEY_F6,
  KEY_LOAD,  // l
  KEY_SAVE,  // s
  KEY_RUN,   // r
  KEY_STEP,  // t
  KEY_RESET, // i
  KEY_UNKNOWN
};

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_mytermrestore (void);
int rk_mytermsave (void);
int rk_readkey (enum keys *key);
int rk_readvalue (int *value, int timeout);

#endif