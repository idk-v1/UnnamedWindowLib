#include "idk/include/idk_file.h"
#include "idk/include/idk_image.h"
#include "idk/include/idk_input.h"
#include "idk/include/idk_time.h"
#include "idk/include/idk_window.h"

int main(int argc, char* argv[])
{
	idk_HWindow window = idk_window("test", 800, 600, -1, -1, idk_flag_darkTheme);

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
			// draw
		}
	}

	idk_window_close(window);

	return 0;
}