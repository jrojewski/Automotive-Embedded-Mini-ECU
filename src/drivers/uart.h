#ifndef UART_H
#define UART_H

#include <stddef.h>
#include <stdint.h>

void uart_init(unsigned long baud);
size_t uart_write(const uint8_t *data, size_t len);
size_t uart_read(uint8_t *data, size_t maxlen);

#endif
