#include <platform.h>
#include <stdbool.h>
#include <lk/debug.h>

int uart_putc(char c) {
    while(!((*(volatile uint32_t *)0x8000100C) & 0x40));
    *(volatile uint32_t *)0x80001004 = c;
    return 0;
}

int uart_getc(bool wait) {
    char c;

    if(((*(volatile uint32_t *)0x8000100C) & 0x10) == 0)
        return -1;
    else {
        c = *(volatile uint32_t *)0x80001008;
        *(volatile uint32_t *)0x8000100c = 0x10;
        return c;
    }
}

void uart_init_early(void) {

}

void uart_init(void) {

}

void platform_dputc(char c) {
    if (c == '\n')
        uart_putc('\r');
    uart_putc(c);
}

int platform_dgetc(char *c, bool wait) {
    int ret = uart_getc(wait);
    if (ret == -1)
        return -1;
    *c = ret;
    return 0;
}

void platform_init(void) {
    uart_init();

}

void platform_early_init(void) {
    uart_init_early();
}

enum handler_return platform_irq(struct arm_iframe *frame) {
    PANIC_UNIMPLEMENTED;
}

enum handler_return platform_fiq(struct arm_iframe *frame) {
    PANIC_UNIMPLEMENTED;
}
