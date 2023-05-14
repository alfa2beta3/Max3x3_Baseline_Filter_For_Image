#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include "max.h"

const int WIDTH = 512;
const int HEIGHT = 512;

using namespace std;

int main()
{
    std::ifstream file("lenna512.dat");
    int pixelValue;
    int **image = (int**)malloc(HEIGHT * sizeof(int*));
    int **filteredImage = (int**)malloc(HEIGHT * sizeof(int*));
    int newimage[512][512];

    if (!file)
    {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        image[i] = (int*)malloc(WIDTH * sizeof(int));
        filteredImage[i] = (int*)malloc(WIDTH * sizeof(int));
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
    
        for (int y = 1; y < HEIGHT - 1; y++)
    {
        for (int x = 1; x < WIDTH - 1; x++)
        {
            
            //
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    newimage[1+dy][1+dx]= image[y + dy][x + dx];
                    
                }
            }
            //
            filteredImage[y][x] = maximumFilter3x3(newimage,x,y);

        }
    }

    clock_t endTime = clock();
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    std::cout << "Time taken to apply maximum filter: " << timeTaken << " seconds" << std::endl;

    std::ofstream outFile("new_lenna512.dat");
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

    std::cout << "Filtered image saved to: new_lenna512.dat" << std::endl;

    // Free the memory allocated for image and filteredImage arrays
    for (int i = 0; i < HEIGHT; i++)
    {
        free(image[i]);
        free(filteredImage[i]);
    }
    free(image);
    free(filteredImage);

    return 0;
}