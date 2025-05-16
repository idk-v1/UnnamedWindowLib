#include "idk/idk_window.h"
#include "idk/idk_input.h"

int main(int argc, char* argv[])
{
	idk_HWindow window = idk_window("test", 800, 600, -1, -1, 0);

	while (idk_window_isOpen(window))
	{
		idk_window_updateAll();
		idk_input_update();

		idk_image_fill(idk_window_getFrameBuf(window), idk_color(0, 0, 0, 255));
		idk_window_display(window);
	}

	idk_window_close(window);

	return 0;
}