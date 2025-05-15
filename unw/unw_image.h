#pragma once

#include "unw_util.h"
#include "image/unw_imageFormat.h"

// Depending on platform, change color format struct
typedef struct unw_Color unw_Color;

unw_Color unw_color(unw_byte r, unw_byte g, unw_byte b, unw_byte a);

typedef struct unw_Image
{
	unw_Color* data;
	unw_vec2u size;
} unw_Image;

#define this_ unw_Image* this


unw_Image unw_image(uint64_t width, uint64_t height);

bool unw_image_resize(this_, uint64_t width, uint64_t height);

void unw_image_clear(this_, unw_Color color);

void unw_d_image(this_);

#undef this_