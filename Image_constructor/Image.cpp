#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

std::vector<unsigned char> generate_some_image(int wd, int hgt)
{
    // this is just an example for tutorial purposes ... generate a red circle
    // in a white field.

    std::vector<unsigned char> data(wd * hgt * 4);

    int c_x = wd / 2;
    int c_y = hgt / 2;
    int radius = c_x;
    int i = 0;
    for (int y = 0; y < hgt; y++) {
        for (int x = 0; x < wd; x++) {
            if ((x - c_x) * (x - c_x) + (y - c_y) * (y - c_y) <= radius * radius) {
                data[i++] = 255;
                data[i++] = 0;
                data[i++] = 0;
                data[i++] = 255;
            } else {
                data[i++] = 255;
                data[i++] = 255;
                data[i++] = 255;
                data[i++] = 255;
            }
        }
    }

    return data;
}

int main()
{
    const int wd = 128;
    const int hgt = 128;
    std::vector<unsigned char> data = generate_some_image(wd, hgt);
    return stbi_write_png( "c:\\test\\foo.png", wd, hgt, 4, &(data[0]), 4*wd);
}