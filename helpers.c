#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // calculate the algorithme in a new variable
            int sepiaRed = (int)round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (int)round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int)round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // cheak the codition
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            // cheak the codition
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            // cheak the codition
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Do the asignment
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // storing the original value in a new variabl
    int original_red[height][width];
    int original_green[height][width];
    int original_blue[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original_red[i][j] = image[i][j].rgbtRed;
            original_green[i][j] = image[i][j].rgbtGreen;
            original_blue[i][j] = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width + 1; j++)
        {
            // reflect the pixels
            image[i][j].rgbtRed = original_red[i][width - j - 1];
            image[i][j].rgbtGreen = original_green[i][width - j - 1];
            image[i][j].rgbtBlue = original_blue[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // storing the original values
    int original_red[height][width];
    int original_green[height][width];
    int original_blue[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original_red[i][j] = image[i][j].rgbtRed;
            original_green[i][j] = image[i][j].rgbtGreen;
            original_blue[i][j] = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //cheaking the condition to calculate the avrerage
            int red = 0;
            int green = 0;
            int blue = 0;
            int index = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if ((i - 1 + k) >= 0 && (j - 1 + l) >= 0 && (i - 1 + k) < height && (j - 1 + l) < width)
                    {
                        index += 1;
                        red += original_red[i - 1 + k][j - 1 + l];
                        green += original_green[i - 1 + k][j - 1 + l];
                        blue += original_blue[i - 1 + k][j - 1 + l];
                    }
                }
            }
            image[i][j].rgbtRed = (int)round(red / (float)index);
            image[i][j].rgbtGreen = (int)round(green / (float)index);
            image[i][j].rgbtBlue = (int)round(blue / (float)index);
        }
    }
    return;
}
