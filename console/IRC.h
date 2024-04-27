#ifndef _IRC_H
#define _IRC_H 1

#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include "sc_helpers.h"
#include "CU.h"

void setSignals();
void IRC(int signum);

#endif