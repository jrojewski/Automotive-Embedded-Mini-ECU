#ifndef HAL_UART_H
#define HAL_UART_H

#include <stddef.h>
#include <stdint.h>

void hal_uart_init(unsigned long baud);
size_t hal_uart_write(const uint8_t *data, size_t len);
size_t hal_uart_read(uint8_t *data, size_t maxlen);

#endif // HAL_UART_H
