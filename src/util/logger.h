#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>

void logger_init(void);
void logger_printf(const char *level, const char *fmt, ...);

#define LOG_INFO(fmt, ...) logger_printf("INFO", fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) logger_printf("WARN", fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) logger_printf("ERROR", fmt, ##__VA_ARGS__)

#endif // LOGGER_H
