#include "unw/unw.h"


int main(int argc, char* argv[])
{
	unw_Window window = unw_window("test", 800, 600, 0);

	while (unw_window_isOpen(&window))
	{
		unw_window_update(&window);
		unw_input_update();

		unw_image_clear(&window.framebuf, unw_color(0, 0, 0, 255));

		unw_window_display(&window);
	}
	unw_d_window(&window);

	return 0;
}