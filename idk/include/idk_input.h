#pragma once

#include "idk_util.h"
#include "idk_window.h"

extern idk_byte* idk_keyStates;
extern idk_byte lastTyped;

void     idk_input_update();

bool     idk_mouse_isPressed(idk_byte button);
bool     idk_mouse_isReleased(idk_byte button);
bool     idk_mouse_isDown(idk_byte button);
void     idk_mouse_setClick(idk_byte button, bool state);

idk_Vec2 idk_mouse_getPos(idk_HWindow window);
void     idk_mouse_setPos(idk_HWindow window, idk_int x, idk_int y);
void     idk_mouse_setPosV(idk_HWindow window, idk_Vec2 pos);

bool     idk_key_isPressed(idk_byte button);
bool     idk_key_isReleased(idk_byte button);
bool     idk_key_isDown(idk_byte button);
void     idk_key_setKey(idk_byte key, bool state);

char     idk_key_typed();