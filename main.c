#include "idk/idk_window.h"
#include "idk/idk_input.h"
#include "idk/idk_time.h"

int main(int argc, char* argv[])
{
	idk_HWindow window = idk_window("test", 800, 600, -1, -1, 0);

	idk_Time lastTime = idk_time_now();
	idk_Time fpsTime = idk_time_now();

	while (idk_window_isOpen(window))
	{
		idk_window_updateAll();
		idk_input_update();

		while (idk_time_timerLoop(&lastTime, 1000 / 60))
		{
			// update
		}

		if (idk_time_timer(&fpsTime, 1000 / 60))
		{
			idk_image_fill(idk_window_getFrameBuf(window), idk_color(0, 0, 0, 255));
			idk_window_display(window);
		}
	}

	idk_window_close(window);

	return 0;
}