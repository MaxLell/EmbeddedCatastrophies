#include "log.h"
#include <stdarg.h>
#include <stdio.h>

void log_info(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("[INFO] - ");
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}
