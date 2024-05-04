#ifndef _IRC_H
#define _IRC_H 1

#include "CU.h"
#include "sc_helpers.h"
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void setSignals ();
void IRC (int signum);

#endif