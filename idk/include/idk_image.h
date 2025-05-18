#pragma once

#include "idk_util.h"
#include "idk_colorFormat.h"
#include "idk_shape.h"

typedef struct idk_Image
{
	idk_Color* pixels;
	idk_Vec2  size;
} idk_Image;


idk_Image idk_image(idk_uint width, idk_uint height, idk_Color fill);
idk_Image idk_imageL(const char* path);

idk_Vec2  idk_image_getSize(idk_Image* image);
void      idk_image_setSize(idk_Image* image, idk_uint width, idk_uint height);

void      idk_image_fill(idk_Image* image, idk_Color fill);
void      idk_image_replace(idk_Image* image, idk_Color target, idk_Color newColor);

void      idk_image_setPixel(idk_Image* image, idk_uint x, idk_uint y, idk_Color color);
void      idk_image_setPixelV(idk_Image* image, idk_Vec2 pos, idk_Color color);

idk_Color idk_image_getPixel(idk_Image* image, idk_uint x, idk_uint y);
idk_Color idk_image_getPixelV(idk_Image* image, idk_Vec2 pos);

bool      idk_image_save(idk_Image* image, const char* path);

void      idk_image_delete(idk_Image* image);