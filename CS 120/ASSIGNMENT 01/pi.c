#include <math.h>   /* Include math library for Square Function for circle_pi */

double circle_pi(int num_rectangles)
{
    double x, height, areaRect = 0, width;
    int i;
    double radius = 2;

    width = radius / num_rectangles;

    for(i=0; i < num_rectangles; ++i)
    {
        x = (i * width) + width / 2;
        height = sqrt(radius * radius - x * x);
        areaRect += width * height;
    }
    return areaRect;
}


double leibniz_pi(int num_iterations)   /* Function for formulating pi using Gottfried Leibniz's method */
{
    int i;
    double divisorTop,divisorBot;
    double divisor, result = 0.0;

    divisorTop = -1.0;


    i = 0;
    while (i < num_iterations)
    {
    divisorTop*= -1.0;
    divisorBot = (2*i) +1;

    divisor = divisorTop / divisorBot;
    result += divisor;
    ++i;
    }
    result *= 4;
   return result;   /* Returns the leibniz_pi calculated result */
}
