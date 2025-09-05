#include <stdio.h>
#include <stdint.h>
#include "uart.h"

void hal_uart_init(unsigned long baud) { (void)baud; }

size_t hal_uart_write(const uint8_t *data, size_t len) 
{
    return fwrite(data, 1, len, stdout);
}

size_t hal_uart_read(uint8_t *data, size_t maxlen) 
{
    return fread(data, 1, maxlen, stdin);
}
