#pragma once

#include "idk_util.h"
#include "idk_image.h"

typedef struct idk_Window
{
	void* handle;
	char* title;
	idk_vec2  pos;
	idk_vec2  size;
	idk_Image frameBuf;
	uint64_t  flags;
} idk_Window;

typedef uint64_t idk_HWindow;

idk_HWindow idk_window(char* title, idk_uint width, idk_uint height, idk_int x, idk_int y, idk_flags flags);

char*       idk_window_getTitle(idk_HWindow window);
void        idk_window_setTitle(idk_HWindow window, char* title);

idk_vec2    idk_window_getSize(idk_HWindow window);
void        idk_window_setSize(idk_HWindow window, idk_uint width, idk_uint height);
idk_vec2    idk_window_getPos(idk_HWindow window);
void        idk_window_setPos(idk_HWindow window, idk_int x, idk_int y);

void        idk_window_maximize(idk_HWindow window);
void        idk_window_minimize(idk_HWindow window);
void        idk_window_normalize(idk_HWindow window);
void        idk_window_fullscreen(idk_HWindow window);
void        idk_window_setVisible(idk_HWindow window, bool state);

void        idk_window_display(idk_HWindow window);

idk_Window* idk_window_getObject(idk_HWindow window);

void        idk_window_close(idk_HWindow window);