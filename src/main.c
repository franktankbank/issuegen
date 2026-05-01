#include <unistd.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

#include "../inc/timedate.h"
#include "../inc/file.h"

int main() {
    // Get tty line
    char* tty_path = ttyname(STDIN_FILENO);

    if (tty_path == NULL) {
        perror("ttyname failed");
        return EXIT_FAILURE;
    }

    char* tty = basename(tty_path);

    tty_info tt_info = {
        .str = tty,
        .len = strlen(tty)
    };

    // Get hostname
    char hostname[1024];

    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname failed");
        return EXIT_FAILURE;
    }

    host_info h_info = {
        .str = hostname,
        .len = strlen(hostname)
    };

    // Get kernel release
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname");
        return EXIT_FAILURE;
    }

    kernel_info k_info = {
        .str = buffer.release,
        .len = strlen(buffer.release)
    };

    time_and_date_t td;
    get_time_and_date(&td);

    time_info ti_info;
    strcpy(ti_info.str, td.time.str),
    ti_info.len = td.time.len;

    date_info d_info;
    strcpy(d_info.str, td.date.str),
    d_info.len = td.date.len;

    init("/etc/issue");

    general_info info = {
        .kernel = k_info,
        .host = h_info,
        .tty = tt_info,
        .date = d_info,
        .time = ti_info
    };

    write_to_issue(info);

    deinit();
    return EXIT_SUCCESS;
}
