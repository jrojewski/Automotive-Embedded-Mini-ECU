#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

void logger_init(void) {}

void logger_printf(const char *level, const char *fmt, ...) 
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stdout, "[%s] ", level);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
    va_end(ap);
}