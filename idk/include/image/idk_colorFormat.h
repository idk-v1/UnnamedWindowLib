#pragma once

#include "../utility/idk_util.h"

typedef struct idk_Color
{
#ifdef _WIN32
		idk_byte a, r, g, b;
#else
		idk_byte r, g, b, a;
#endif
} idk_Color;

static inline idk_Color idk_color(idk_byte r, idk_byte g, idk_byte b, idk_byte a)
{
	idk_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}