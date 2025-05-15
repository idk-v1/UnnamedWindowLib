#pragma once
#include "unw_util.h"
#include "unw_image.h"

typedef struct unw_Window
{
	void* handle;

	unw_Image framebuf;

	unw_vec2i pos;
	unw_vec2u size;
	
	uint64_t flags;
} unw_Window;

extern uint64_t _unw_windowCount;

#define this_ unw_Window* this


unw_Window unw_window(const char* title, uint64_t width, uint64_t height, uint64_t flags);

bool  unw_window_isOpen(this_);

void unw_window_update(this_);

void unw_window_display(this_);

void unw_d_window(this_);


#undef this_