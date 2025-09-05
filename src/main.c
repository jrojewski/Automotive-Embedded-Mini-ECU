#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include "core/scheduler.h"
#include "util/logger.h"
#include "hal/uart.h"

// Forward deklaracja z diag
void diag_cli_init(void);
void diag_cli_process(void);

static void task_cli(void) { diag_cli_process(); }

int main(void) 
{
    logger_init();
    hal_uart_init(115200);
    LOG_INFO("MiniECU starting");

    scheduler_init();
    scheduler_add(task_cli, 5); // Executes CLI processing every 5 ms.
    
    diag_cli_init();

    // Generates a 1 ms tick for host-based simulation.
    struct timespec ts = {0, 1000000};
    
    while (1) 
    {
        nanosleep(&ts, NULL);
        scheduler_tick_isr();
        scheduler_run();
    }

    return 0;
}