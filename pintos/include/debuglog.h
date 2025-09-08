#pragma once
#include "threads/interrupt.h"
#include "devices/timer.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef LOG_ON
static inline void _logf_impl(const char *func, const char *fmt, ...)
{
    enum intr_level old = intr_disable();
    printf("[%-10s][%lld] ", func, (long long)timer_ticks());

    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    printf("\n");
    intr_set_level(old);
}
#define LOGF(fmt, ...) _logf_impl(__func__, fmt, ##__VA_ARGS__)
#else
#define LOGF(...) ((void)0)
#endif

#define TINFO(t) (t)->name, (int)(t)->tid, (int)(t)->priority