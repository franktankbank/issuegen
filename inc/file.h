#ifndef FILE_H
#define FILE_H

#include "info.h"

void init(const char* filepath);

void deinit();

int write_to_issue(general_info info);

#endif // FILE_H
