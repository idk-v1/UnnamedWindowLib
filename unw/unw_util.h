#pragma once

#ifdef __cplusplus
#define UNWFN extern "C"
#else
#define UNWFN
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t unw_byte;

typedef struct unw_vec2
{
	int64_t x, y;
} unw_vec2;

typedef struct unw_rect
{
	int64_t x, y, w, h;
} unw_rect;