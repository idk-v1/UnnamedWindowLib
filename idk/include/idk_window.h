#pragma once

#include "utility/idk_util.h"
#include "idk_image.h"
#include "utility/idk_array.h"
#include "window/idk_windowStruct.h"

IDK_ARRAY_TEMPLATE(idk_Window, idk_WindowList)

extern idk_WindowList _idk_windowList;
idk_HWindow idk_window_fromHandle(void* handle);


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

bool        idk_window_isOpen(idk_HWindow window);

void        idk_window_update(idk_HWindow window);
void        idk_window_updateAll();

idk_Image*  idk_window_getFrameBuf(idk_HWindow window);
void        idk_window_display(idk_HWindow window);

void        idk_window_close(idk_HWindow window);


idk_Image   idk_display_screenshot();
idk_Vec2    idk_display_getSize();


idk_HTrayIcon idk_window_addTrayIcon(idk_HWindow window, idk_Image* icon, const char* hoverText);
void          idk_trayIcon_setIcon(idk_HTrayIcon trayIcon, idk_Image* icon);
void          idk_trayIcon_setText(idk_HTrayIcon trayIcon, const char* hoverText);
void          idk_window_removeTrayIcon(idk_HWindow window, idk_HTrayIcon);