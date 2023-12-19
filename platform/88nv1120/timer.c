#include <sys/types.h>
#include <lk/debug.h>
#include <lk/err.h>
#include <lk/reg.h>
#include <kernel/thread.h>
#include <platform/timer.h>

#define TIMER_TICK_RATE 32768

static volatile lk_time_t ticks = 0;
static lk_time_t tick_interval;
static platform_timer_callback time_callback;
static void *callback_arg;

static enum handler_return timer_irq(void *arg) {
    ticks += tick_interval;
    return time_callback(callback_arg, ticks);
}

status_t platform_set_periodic_timer(platform_timer_callback callback, void *arg, lk_time_t interval) {

    return NO_ERROR;
}

lk_time_t current_time(void) {
    return ticks;
}

lk_bigtime_t current_time_hires(void) {
    lk_bigtime_t time;

    time = (lk_bigtime_t)ticks * 1000;
    return time;
}

