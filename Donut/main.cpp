#include <iostream>


using namespace std;

int main() {

	int width = 120;
	int height = 30;
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;

	char* screen = new char[width * height + 1];
	char gardient[] = " .:!/r(l1Z4H9W8$@";
	int gardientSize = size(gardient)-2;

	screen[width * height] = '\0';

	for (int t = 0; t < 100000; t++) {

		for (int i = 0; i < width; i++) {

			for (int j = 0; j < height; j++) {

				float x = (float)i * 2.0f / width - 1.0f;
				float y = (float)j * 2.0f / height - 1.0f;
				x *= aspect * pixelAspect;
				x += sin(t*0.001f);
				char pixel = ' ';
				float dist = sqrt(x * x + y * y);
				int color = (int)(1.0f / dist);
				if (color < 0) color = 0;
				else if (color > gardientSize) color = gardientSize;
				pixel = gardient[color];

				/*if (x * x + y * y < 0.5) {
					pixel = '@';
				}*/

				if (x * x + y * y < 0.1) {
					pixel = ' ';
				}
				screen[i + j * width] = pixel;
			}
		}

		printf(screen);
	}

	

	getchar();

}

