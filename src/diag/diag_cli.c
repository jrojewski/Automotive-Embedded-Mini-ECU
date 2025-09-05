#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "diag_cli.h"
#include "util/logger.h"
#include "drivers/uart.h"

static char line[128];
static size_t len = 0;

static void send(const char *s) { uart_write((const uint8_t*)s, strlen(s)); }

void diag_cli_init(void) 
{
    LOG_INFO("CLI ready. Type HELP");
}

void diag_cli_process(void) 
{
    uint8_t ch;

    while (uart_read(&ch, 1) == 1) 
    {
        if (ch == '\n' || ch == '\r') 
        {
            line[len] = '\0';

            if (len > 0) 
            {
                if (strcmp(line, "HELP") == 0) 
                {
                    send("Commands: HELP, ECHO <text>, VERSION\n");
                } else if (strncmp(line, "ECHO ", 5) == 0) 
                {
                    send(line + 5); send("\n");
                } else if (strcmp(line, "VERSION") == 0) 
                {
                    send("MiniECU v0.1\n");
                } else 
                {
                    send("ERR: Unknown command\n");
                }
            }

            len = 0;
        } 
        else if (len + 1 < sizeof(line)) 
        {
            line[len++] = (char)ch;
        }
    }
}
