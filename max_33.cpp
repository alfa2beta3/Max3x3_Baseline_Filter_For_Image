const int WIDTH = 512;
const int HEIGHT = 512;

void maximumFilter3x3(int image[HEIGHT][WIDTH], int filteredImage[HEIGHT][WIDTH])
{
    for (int y = 1; y < HEIGHT - 1; y++)
    {
        for (int x = 1; x < WIDTH - 1; x++)
        {
            int maxVal = 0;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int pixelVal = image[y + dy][x + dx];
                    if (pixelVal > maxVal)
                        maxVal = pixelVal;
                }
            }

            filteredImage[y][x] = maxVal;

        }
    }
}
