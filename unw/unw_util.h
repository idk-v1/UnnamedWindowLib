#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t unw_byte;

typedef struct unw_vec2i
{
	int64_t x, y;
} unw_vec2i;

typedef struct unw_vec2u
{
	uint64_t x, y;
} unw_vec2u;

typedef struct unw_rect
{
	int64_t x, y, w, h;
} unw_rect;