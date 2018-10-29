#include <stdio.h>
#include <math.h>
/* 
int main()
{
    double divisorTop,divisorBot;
    double sum, divisor, result = 0.0;
    divisorTop = -1.0;


    int i = 0;
    while (i < 100)
    {
    divisorTop*= -1.0;
    divisorBot = (2*i) +1;

    divisor = divisorTop / divisorBot;
    printf("Divisor: %f\n", divisor);
    result += divisor;
    printf("Result: %f\n\n", result);

    ++i;
    }


    result *= 4;
    printf("divisor: %f result: %.12f divisorTop: %f divisorBot: %f\n\n", divisor, result, divisorTop, divisorBot);
    return 0;
}
 */
int main()
{
    double x, height, areaRect = 0, result, width, newWidth;
    int i;
    double radius = 2;
    int num_rectangles;
    num_rectangles = 10;

    width = radius / num_rectangles;
    printf("width: %f\n\n", width);

    for(i=0; i < num_rectangles; ++i)
    {
        x = (i * width) + width / 2;
        height = sqrt(radius * radius - x * x);
        areaRect += width * height;
        printf("AreaRect: %f newWidth: %f Height: %f x: %f\n", areaRect,width, height, radius, x);
    }
    printf("Result: %.12f\n", areaRect);
    return areaRect;
}


