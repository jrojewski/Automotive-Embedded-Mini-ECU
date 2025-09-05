#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*task_fn_t)(void);

void scheduler_init(void);
int scheduler_add(task_fn_t fn, uint32_t period_ms);
void scheduler_tick_isr(void); // wywoływane co 1 ms
void scheduler_run(void);

#endif // SCHEDULER_H
