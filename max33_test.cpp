#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "max.cpp"
#include <time.h>

using namespace std;
int main()
{
    std::ifstream file("/dsp_max_filter/testbench/lenna512.dat");
    int pixelValue;
    int image[HEIGHT][WIDTH];
    int filteredImage[HEIGHT][WIDTH];

    if (!file)
    {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (file >> pixelValue)
            {
                image[i][j] = pixelValue;
            }
            else
            {
                std::cout << "Failed to read pixel value from the input file." << std::endl;
                file.close();
                return 1;
            }
        }
    }

    file.close();

    clock_t startTime = clock();

    maximumFilter3x3(image, filteredImage);

    clock_t endTime = clock();
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    std::cout << "Time taken to apply maximum filter: " << timeTaken << " seconds" << std::endl;

    std::ofstream outFile("/dsp_max_filter/testbench/new_lenna512.dat");
    if (!outFile)
    {
        std::cout << "Failed to open the output file." << std::endl;
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            outFile << filteredImage[i][j] << "\n";
        }
    }

    outFile.close();

    std::cout << "Filtered image saved to: /content/new_lenna512.dat" << std::endl;

    return 0;
}
