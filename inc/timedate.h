#ifndef TIME_H
#define TIME_H

#include <stdint.h>

#include "info.h"

typedef struct {
    date_info date;
    time_info time;
} time_and_date_t;

void get_time_and_date(time_and_date_t *td);

#endif // TIME_H
