#include "idk/include/idk_file.h"
#include "idk/include/idk_image.h"
#include "idk/include/idk_input.h"
#include "idk/include/idk_time.h"
#include "idk/include/idk_window.h"

int main(int argc, char* argv[])
{
	idk_RawFile file = idk_file_read("res", "scores.txt");
	idk_Image sprites = idk_imageL("res/spritesheet.png");

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

			idk_image_drawImage(idk_window_getFrameBuf(window), &sprites, 0, 0, 64, 64, 16, 0);

			idk_window_display(window);
		}
	}

	idk_window_close(window);

	idk_image_delete(&sprites);

	idk_file_write("res", "scores.txt", file.data, file.length);
	idk_RawFile_delete(&file);

	return 0;
}