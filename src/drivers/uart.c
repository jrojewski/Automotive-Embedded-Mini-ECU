#include <stdio.h>
#include <string.h>
#include "hal/uart.h"
#include "core/ring_buffer.h"

#define UART_RX_BUF_SZ 256
#define UART_TX_BUF_SZ 256

static uint8_t rx_mem[UART_RX_BUF_SZ];
static uint8_t tx_mem[UART_TX_BUF_SZ];
static ring_buffer_t rx_rb, tx_rb;

void uart_init(unsigned long baud) 
{
    hal_uart_init(baud);
    rb_init(&rx_rb, rx_mem, UART_RX_BUF_SZ);
    rb_init(&tx_rb, tx_mem, UART_TX_BUF_SZ);
}

size_t uart_write(const uint8_t *data, size_t len) 
{
    return hal_uart_write(data, len);
}

size_t uart_read(uint8_t *data, size_t maxlen) 
{
    return hal_uart_read(data, maxlen);
}
