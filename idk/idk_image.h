#pragma once

#include "idk_util.h"
#include "idk_colorFormat.h"

typedef struct idk_Image
{
	idk_Color* pixels;
	idk_Vec2  size;
} idk_Image;


idk_Image idk_image(idk_uint width, idk_uint height, idk_Color fill);

idk_Vec2  idk_image_getSize(idk_Image* image);
void      idk_image_setSize(idk_Image* image, idk_uint width, idk_uint height);

void      idk_image_fill(idk_Image* image, idk_Color fill);
void      idk_image_replace(idk_Image* image, idk_Color target, idk_Color newColor);


void      idk_image_setRect(idk_Image* image, idk_int x, idk_int y, idk_int width, idk_int height, idk_Color color);
void      idk_image_setRectV(idk_Image* image, idk_Vec2 pos, idk_Vec2 size, idk_Color color);
void      idk_image_setRectR(idk_Image* image, idk_Rect rect, idk_Color color);

void      idk_image_setRectF(idk_Image* image, idk_int x, idk_int y, idk_int width, idk_int height, idk_Color color);
void      idk_image_setRectFV(idk_Image* image, idk_Vec2 pos, idk_Vec2 size, idk_Color color);
void      idk_image_setRectFR(idk_Image* image, idk_Rect rect, idk_Color color);

void      idk_image_drawRect(idk_Image* image, idk_int x, idk_int y, idk_int width, idk_int height, idk_Color color);
void      idk_image_drawRectV(idk_Image* image, idk_Vec2 pos, idk_Vec2 size, idk_Color color);
void      idk_image_drawRectR(idk_Image* image, idk_Rect rect, idk_Color color);

void      idk_image_drawRectF(idk_Image* image, idk_int x, idk_int y, idk_int width, idk_int height, idk_Color color);
void      idk_image_drawRectFV(idk_Image* image, idk_Vec2 pos, idk_Vec2 size, idk_Color color);
void      idk_image_drawRectFR(idk_Image* image, idk_Rect rect, idk_Color color);


void      idk_image_setCircle(idk_Image* image, idk_int x, idk_int y, idk_int radius, idk_Color color);
void      idk_image_setCircleV(idk_Image* image, idk_Vec2 pos, idk_int radius, idk_Color color);

void      idk_image_setCircleF(idk_Image* image, idk_int x, idk_int y, idk_int radius, idk_Color color);
void      idk_image_setCircleFV(idk_Image* image, idk_Vec2 pos, idk_int radius, idk_Color color);

void      idk_image_drawCircle(idk_Image* image, idk_int x, idk_int y, idk_int radius, idk_Color color);
void      idk_image_drawCircleV(idk_Image* image, idk_Vec2 pos, idk_int radius, idk_Color color);

void      idk_image_drawCircleF(idk_Image* image, idk_int x, idk_int y, idk_int radius, idk_Color color);
void      idk_image_drawCircleFV(idk_Image* image, idk_Vec2 pos, idk_int radius, idk_Color color);


void      idk_image_setLine(idk_Image* image, idk_int x0, idk_int y0, idk_int x1, idk_int y1, idk_Color color);
void      idk_image_setLineV(idk_Image* image, idk_Vec2 pt0, idk_Vec2 pt1, idk_Color color);

void      idk_image_drawLine(idk_Image* image, idk_int x0, idk_int y0, idk_int x1, idk_int y1, idk_Color color);
void      idk_image_drawLineV(idk_Image* image, idk_Vec2 pt0, idk_Vec2 pt1, idk_Color color);


void      idk_image_setImage(idk_Image* image, idk_Image* other, idk_int x, idk_int y, idk_int width, idk_int height, idk_int offsetX, idk_int offsetY);
void      idk_image_setImageV(idk_Image* image, idk_Image* other, idk_Vec2 pos, idk_Vec2 size, idk_Vec2 offset);
void      idk_image_setImageR(idk_Image* image, idk_Image* other, idk_Vec2 pos, idk_Rect imgRect);

void      idk_image_drawImage(idk_Image* image, idk_Image* other, idk_int x, idk_int y, idk_int width, idk_int height, idk_int offsetX, idk_int offsetY);
void      idk_image_drawImageV(idk_Image* image, idk_Image* other, idk_Vec2 pos, idk_Vec2 size, idk_Vec2 offset);
void      idk_image_drawImageR(idk_Image* image, idk_Image* other, idk_Vec2 pos, idk_Rect imgRect);


void      idk_image_delete(idk_Image* image);
