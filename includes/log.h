#ifndef LOG_H
#define LOG_H

#include "stdio.h"
#include "time.h"

#ifdef  DEBUG

#define LOG(...)    printf(__VA_ARGS__); \
                    fflush(stdout)
#endif
#ifndef DEBUG
#define LOG(...)
#endif

#endif // LOG_H
