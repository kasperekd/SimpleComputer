#pragma once
#ifndef _PRINT_H
#define _PRINT_H 1
#include <stdio.h>

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
int rk_mytermrestore (void);
int rk_mytermsave (void);
int rk_readkey (enum keys *);
int rk_readvalue (int *value, int timeout)

#endif