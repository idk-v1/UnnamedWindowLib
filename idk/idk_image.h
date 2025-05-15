#pragma once

#include "idk_util.h"
#include "idk_colorFormat.h"

typedef struct idk_Image
{
	idk_Color* pixels;
	idk_vec2  size;
} idk_Image;


idk_Image idk_image(idk_uint width, idk_uint height, idk_Color fill);

idk_vec2  idk_image_getSize(idk_Image* image);
void      idk_image_setSize(idk_Image* image, idk_uint width, idk_uint height);

void      idk_image_fill(idk_Image* image, idk_Color fill);
void      idk_image_replace(idk_Image* image, idk_Color target, idk_Color newColor);

void      idk_image_drawRect(idk_Image* image, idk_int x, idk_int y, idk_int width, idk_int height, idk_Color color, bool fill);
void      idk_image_drawCircle(idk_Image* image, idk_int x, idk_int y, idk_int radius, idk_Color color, bool fill);
void      idk_image_drawLine(idk_Image* image, idk_int x0, idk_int y0, idk_int x1, idk_int y1, idk_Color color);

void      idk_image_drawImage(idk_Image* image, idk_Image* other, idk_int x, idk_int y, idk_int width, idk_int height, idk_int offsetX, idk_int offsetY);

void      idk_image_delete(idk_Image* image);
