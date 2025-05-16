#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t idk_byte;

typedef int32_t idk_int;
typedef uint32_t idk_uint;

typedef uint64_t idk_flags;

typedef struct idk_Vec2
{
	idk_int x, y;
} idk_Vec2;

static idk_Vec2 idk_vec2(idk_int x, idk_int y)
{
	idk_Vec2 vec;
	vec.x = x;
	vec.y = y;
	return vec;
}

typedef struct idk_Rect
{
	idk_int x, y, w, h;
} idk_Rect;

static idk_Rect idk_rect(idk_int x, idk_int y, idk_int w, idk_int h)
{
	idk_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}