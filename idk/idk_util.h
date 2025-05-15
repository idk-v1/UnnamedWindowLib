#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t idk_byte;

typedef int32_t idk_int;
typedef uint32_t idk_uint;

typedef uint64_t idk_flags;

typedef struct idk_vec2
{
	idk_int x, y;
} idk_vec2;

typedef struct idk_rect
{
	idk_int x, y, w, h;
} idk_rect;

#include "idk_memory.h"
#include "idk_array.h"