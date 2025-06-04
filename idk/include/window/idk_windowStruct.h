#pragma once

#include "../utility/idk_util.h"
#include "../idk_image.h"

typedef struct idk_Window
{
	void* handle;
	char* title;
	idk_Vec2  pos;
	idk_Vec2  size;
	idk_Image frameBuf;
	uint64_t  flags;
} idk_Window;

typedef uint64_t idk_HWindow;


typedef struct idk_TrayIcon
{
	idk_Image icon;
	char* hoverText;

} idk_TrayIcon;

typedef uint64_t idk_HTrayIcon;


idk_flags idk_flag_normal = 0;
idk_flags idk_flag_hidden = 1 << 0;
idk_flags idk_flag_noResize = 1 << 1;
idk_flags idk_flag_borderless = 1 << 2;
idk_flags idk_flag_fullscreen = 1 << 3;
idk_flags idk_flag_maximized = 1 << 4;
idk_flags idk_flag_minimized = 1 << 5;
idk_flags idk_flag_closed = 1 << 6;
idk_flags idk_flag_topmost = 1 << 7;
idk_flags idk_flag_AggroTopmost = 1 << 8;
idk_flags idk_flag_passthru = 1 << 9;
idk_flags idk_flag_hideTaskbar = 1 << 10;
idk_flags idk_flag_darkTheme = 1 << 11;
idk_flags idk_flag_captureMouse = 1 << 12;