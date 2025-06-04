#pragma once

#include "utility/idk_util.h"

typedef uint64_t idk_Time;

idk_Time idk_time_now();

idk_Time idk_time_diff(idk_Time old);

bool idk_time_timer(idk_Time* old, idk_Time duration);
bool idk_time_timerLoop(idk_Time* old, idk_Time duration);

void idk_time_sleep(idk_Time duration);


static const char* idk_date_dayNames[] =
{
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};
static const char* idk_date_monthNames[] =
{
	"Janurary",
	"Feburary",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

typedef struct idk_DateTime
{
	idk_byte day, month, year;
	idk_byte hour, minute, second;
} idk_DateTime;

idk_DateTime idk_date_get();