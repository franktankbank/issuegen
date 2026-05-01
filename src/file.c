#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "../inc/file.h"
#include "../inc/strings.h"
#include "../inc/escape.h"
#include "../inc/info.h"

static FILE* fp;

static void wside_border(bool nl) {
    if (nl == true) {
        fprintf(fp, "%s%s%s\n", BLUE, SIDE_BORDER, RESET);
    } else {
        fprintf(fp, "%s%s%s", BLUE, SIDE_BORDER, RESET);
    }
}

static void wwhitespace(uint32_t n) {
    for (int i = 0; i < n; i++) {
        fprintf(fp, " ");
    }
}

static void wborder(uint32_t n) {
    for (int i = 0; i < n; i++) {
        fprintf(fp, HORIZONTAL_BORDER);
    }
}

void init(const char* filepath) {
    fp = fopen(filepath, "w");
}
void deinit() {
    fclose(fp);
}

int write_to_issue(general_info info) {
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    uint32_t max_width = KERNEL_INFO_SPACE_L_LEN + KERNEL_INFO_TITLE_LEN + SPACE_LEN + info.kernel.len + HOST_INFO_SPACE_L_LEN + HOST_INFO_TITLE_LEN + SPACE_LEN + info.host.len + TTY_INFO_SPACE_L_LEN + TTY_INFO_TITLE_LEN + SPACE_LEN + info.tty.len + TTY_INFO_SPACE_R_LEN;
    uint32_t info_line2_width = DATE_INFO_SPACE_L_LEN + DATE_INFO_TITLE_LEN + SPACE_LEN + info.date.len + TIME_INFO_SPACE_L_LEN + TIME_INFO_TITLE_LEN + SPACE_LEN + info.time.len;
    uint32_t subtitle_space_width = (max_width - SUBTITLE_LEN) / 2;
    uint32_t subtitle_total_width = (subtitle_space_width * 2) + SUBTITLE_LEN;
    uint32_t title_space_width = (max_width - TITLE_LINE_LEN) / 2;
    uint32_t title_total_width = (title_space_width * 2) + TITLE_LINE_LEN;
    uint32_t description_space_width = (max_width - DESCRIPTION_LEN) / 2;
    uint32_t description_total_width = (description_space_width * 2) + DESCRIPTION_LEN;

    fprintf(fp, "%s\n", CLEAR);
    fprintf(fp, "%s%s", BLUE, TOP_LEFT_BORDER);
    wborder(max_width);
    fprintf(fp, "%s%s\n", TOP_RIGHT_BORDER, RESET);

    // Title
    wside_border(false);
    wwhitespace(max_width);
    wside_border(true);

    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE1, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE2, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE3, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE4, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE5, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(title_space_width);
    fprintf(fp, "%s%s%s", MAGENTA, TITLE_LINE6, RESET);
    if (title_space_width == max_width) {
        wwhitespace(title_space_width);
    } else {
        wwhitespace((max_width - title_total_width) + title_space_width);
    }
    wside_border(true);

    // Middle
    wside_border(false);
    wwhitespace(max_width);
    wside_border(true);
    wside_border(false);
    wwhitespace(subtitle_space_width);
    fprintf(fp, "%s%s%s", YELLOW, SUBTITLE, RESET);
    // Just in case subtitle_space_width is a decimal converted to an integer
    if (subtitle_total_width == max_width) {
        wwhitespace(subtitle_space_width);
    } else {
        wwhitespace((max_width - subtitle_total_width) + subtitle_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(max_width);
    wside_border(true);
    wside_border(false);
    fprintf(fp, "%s%s%s%s %s%s%s%s%s %s%s%s%s%s %s%s", KERNEL_INFO_SPACE_L, GREEN, KERNEL_INFO_TITLE, RESET, info.kernel.str, HOST_INFO_SPACE_L, GREEN, HOST_INFO_TITLE, RESET, info.host.str, TTY_INFO_SPACE_L, GREEN, TTY_INFO_TITLE, RESET, info.tty.str, TTY_INFO_SPACE_R);
    wside_border(true);
    wside_border(false);
    fprintf(fp, "%s%s%s%s %s%s%s%s%s %s", DATE_INFO_SPACE_L, GREEN, DATE_INFO_TITLE, RESET, info.date.str, TIME_INFO_SPACE_L, GREEN, TIME_INFO_TITLE, RESET, info.time.str);
    wwhitespace(max_width - info_line2_width);
    wside_border(true);
    wside_border(false);
    wwhitespace(max_width);
    wside_border(true);

    // Bottom
    wside_border(false);
    wwhitespace(description_space_width);
    fprintf(fp, "%s%s%s", RED, DESCRIPTION, RESET);
    if (description_total_width == max_width) {
        wwhitespace(description_space_width);
    } else {
        wwhitespace((max_width - description_total_width) + description_space_width);
    }
    wside_border(true);
    wside_border(false);
    wwhitespace(max_width);
    wside_border(true);
    fprintf(fp, "%s%s", BLUE, BOTTOM_LEFT_BORDER);
    wborder(max_width);
    fprintf(fp, "%s%s\n\n", BOTTOM_RIGHT_BORDER, RESET);

    return 0;
}
