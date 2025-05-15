#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t idk_byte;

typedef struct idk_vec2
{
	int64_t x, y;
} idk_vec2;

typedef struct idk_rect
{
	int64_t x, y, w, h;
} idk_rect;