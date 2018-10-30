/******************************************************************************
Filename:       pi.c
Author:         Kenneth Ong
DP email:       t.ong@digipen.edu
Course:         CS 120
Assignment:     01
Due Date:       04 11 18

Brief Discription
    This file contains the functions for the pi assignment. Both "circle_pi"
    and "leibniz_pi" are created here to test with the main function given.
******************************************************************************/
#include <math.h>                                   /* Include math library for Square Function for circle_pi */

/* Function for formulating pi using the sum of area rectangles method */
double circle_pi(int num_rectangles)
{
    double x, height, areaRect = 0, width;
    int i;
    double radius = 2;

/* Getting the Width by dividing by number of num_rectangles (Iterations) */
    width = radius / num_rectangles;

/* Create a For Loop to find all the areas of the rectangles inside the circle and add them together */
    for(i=0; i < num_rectangles; ++i)
    {

        /* Finding x to input to forumla to find "Height" */
        x = (i * width) + width / 2;
        /* Finding Height of Rectangle */
        height = sqrt(radius * radius - x * x);
        areaRect += width * height;                 /* Finding area of rectangles and sum them up together */
    }
    return areaRect;                                /* Return Pi result in accordance to num_rectangles entered */
}


double leibniz_pi(int num_iterations)               /* Function for formulating pi using Gottfried Leibniz's method */
{
    int i;
    double divisorTop,divisorBot;
    double divisor, result = 0.0;
    divisorTop = -1.0;                              /* Setting DivisorTop to -1 in accordance to formula */

    i = 0;
    while (i < num_iterations)                      /* Declaring i = 0 and running a while loop to loop through the number of iterations */
    {
    divisorTop*= -1.0;                              /* Power of divisorTop by using * the same number "-1^n" */
    divisorBot = (2*i) +1;                          /* Finding the Formula divisor Bottom of "2(N)+1" */
    divisor = divisorTop / divisorBot;              /* Dividing divisorTop by divisorBot to get the result from leibniz's formula */
    result += divisor;                              /* Sum of all results from leibniz's formula */
    ++i;
    }
    result *= 4;                                    /* Multiply result by 4 to get π */
   return result;                                   /* Returns the leibni z_pi calculated result*/
}
