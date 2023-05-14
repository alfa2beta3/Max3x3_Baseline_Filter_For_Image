const int WIDTH = 512;
const int HEIGHT = 512;

int maximumFilter3x3(int newimage[512][512], int x, int y)
{
    
            int maxVal = 0;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int pixelVal = newimage[1 + dy][1 + dx];
                    if (pixelVal > maxVal)
                        maxVal = pixelVal;
                }
            }

            return maxVal;
}
