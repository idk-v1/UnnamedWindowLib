#pragma once

#include "../utility/idk_util.h"
#include "idk_colorFormat.h"
#include "idk_shape.h"

typedef struct idk_Image
{
	idk_Color* pixels;
	idk_Vec2  size;
} idk_Image;