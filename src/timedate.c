#include <time.h>
#include <string.h>

#include "../inc/timedate.h"

void get_time_and_date(time_and_date_t *td) {
    time_t t = time(NULL);
    const struct tm *tm = localtime(&t);
    char date_str[11]; // Format: MM/dd/yyyy + null terminator
    char time_str[6]; // "HH:MM" + null terminator

    strftime(date_str, sizeof(date_str), "%m/%d/%Y", tm);
    strftime(time_str, sizeof(time_str), "%R", tm);

    strcpy(td->date.str, date_str);
    td->date.len = 10;
    strcpy(td->time.str, time_str);
    td->time.len = 5;
}
