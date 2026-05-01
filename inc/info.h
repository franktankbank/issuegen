#ifndef INFO_H
#define INFO_H

#include <stdint.h>

typedef struct {
    char* str;
    uint32_t len;
} kernel_info;

typedef struct {
    char* str;
    uint32_t len;
} host_info;

typedef struct {
    char* str;
    uint32_t len;
} tty_info;

typedef struct {
    char str[11];
    uint32_t len;
} date_info;

typedef struct {
    char str[6];
    uint32_t len;
} time_info;

typedef struct {
    kernel_info kernel;
    host_info host;
    tty_info tty;
    date_info date;
    time_info time;
} general_info;

#endif // INFO_H
