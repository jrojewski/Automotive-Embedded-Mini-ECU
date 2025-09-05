#include "scheduler.h"
#include <stddef.h>

#define MAX_TASKS 8

typedef struct 
{
    task_fn_t fn;
    uint32_t period_ms;
    uint32_t elapsed_ms;
} task_t;

static task_t tasks[MAX_TASKS];
static int task_count = 0;

void scheduler_init(void) 
{
    for (int i = 0; i < MAX_TASKS; ++i) 
    {
        tasks[i].fn = NULL;
        tasks[i].period_ms = 0;
        tasks[i].elapsed_ms = 0;
    }

    task_count = 0;
}

int scheduler_add(task_fn_t fn, uint32_t period_ms) 
{
    if (task_count >= MAX_TASKS || fn == NULL || period_ms == 0) return -1;

    tasks[task_count].fn = fn;
    tasks[task_count].period_ms = period_ms;
    tasks[task_count].elapsed_ms = 0;

    return task_count++;
}

void scheduler_tick_isr(void) 
{
    for (int i = 0; i < task_count; ++i) 
    {
        tasks[i].elapsed_ms++;
    }
}

void scheduler_run(void) 
{
    for (int i = 0; i < task_count; ++i) 
    {
        if (tasks[i].fn && tasks[i].elapsed_ms >= tasks[i].period_ms) 
        {
            tasks[i].elapsed_ms = 0;
            tasks[i].fn();
        }
    }
}
