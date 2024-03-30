#pragma once
#ifndef _READKEY_H
#define _READKEY_H 1
#include <stdio.h>

enum keys
{
 SHIFT = 0,
 SPACE,
};

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_mytermrestore (void);
int rk_mytermsave (void);
int rk_readkey (enum keys *k);
int rk_readvalue (int *value, int timeout);

#endif