#pragma once

#include "idk_util.h"

typedef uint64_t idk_Time;

idk_Time idk_time_now();

idk_Time idk_time_diff(idk_Time old);

bool idk_time_timer(idk_Time* old, idk_Time duration);

void idk_time_sleep(idk_Time duration);