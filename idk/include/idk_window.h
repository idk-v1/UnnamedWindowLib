#pragma once

#include "idk_util.h"
#include "idk_image.h"
#include "idk_array.h"

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

IDK_ARRAY_TEMPLATE(idk_Window, idk_WindowList)

extern idk_WindowList _idk_windowList;
idk_HWindow idk_window_fromHandle(void* handle);


idk_flags idk_flag_normal       =       0;
idk_flags idk_flag_hidden       = 1 <<  0;
idk_flags idk_flag_noResize     = 1 <<  1;
idk_flags idk_flag_borderless   = 1 <<  2;
idk_flags idk_flag_fullscreen   = 1 <<  3;
idk_flags idk_flag_maximized    = 1 <<  4;
idk_flags idk_flag_minimized    = 1 <<  5;
idk_flags idk_flag_closed       = 1 <<  6;
idk_flags idk_flag_topmost      = 1 <<  7;
idk_flags idk_flag_AggroTopmost = 1 <<  8;
idk_flags idk_flag_passthru     = 1 <<  9;
idk_flags idk_flag_hideTaskbar  = 1 << 10;
idk_flags idk_flag_darkTheme    = 1 << 11;


idk_HWindow idk_window(char* title, idk_uint width, idk_uint height, idk_int x, idk_int y, idk_flags flags);
idk_HWindow idk_windowV(char* title, idk_Vec2 size, idk_Vec2 pos, idk_flags flags);

char*       idk_window_getTitle(idk_HWindow window);
void        idk_window_setTitle(idk_HWindow window, char* title);
void        idk_window_setTitleF(idk_HWindow window, char* format, ...);

idk_Vec2    idk_window_getSize(idk_HWindow window);
void        idk_window_setSize(idk_HWindow window, idk_uint width, idk_uint height);
idk_Vec2    idk_window_getPos(idk_HWindow window);
void        idk_window_setPos(idk_HWindow window, idk_int x, idk_int y);

void        idk_window_maximize(idk_HWindow window);
void        idk_window_minimize(idk_HWindow window);
void        idk_window_normalize(idk_HWindow window);
void        idk_window_fullscreen(idk_HWindow window);
void        idk_window_setVisible(idk_HWindow window, bool state);

idk_Window* idk_window_getObject(idk_HWindow window);

bool        idk_window_isOpen(idk_HWindow window);

void        idk_window_update(idk_HWindow window);
void        idk_window_updateAll();

idk_Image*  idk_window_getFrameBuf(idk_HWindow window);
void        idk_window_display(idk_HWindow window);

void        idk_window_close(idk_HWindow window);


idk_Image   idk_display_screenshot();
idk_Vec2    idk_display_getSize();



typedef struct idk_TrayIcon
{
	idk_Image icon;
	char* hoverText;

} idk_TrayIcon;

typedef uint64_t idk_HTrayIcon;

idk_HTrayIcon idk_window_addTrayIcon(idk_HWindow window, idk_Image* icon, const char* hoverText);
void          idk_trayIcon_setIcon(idk_HTrayIcon trayIcon, idk_Image* icon);
void          idk_trayIcon_setText(idk_HTrayIcon trayIcon, const char* hoverText);
void          idk_window_removeTrayIcon(idk_HWindow window, idk_HTrayIcon);