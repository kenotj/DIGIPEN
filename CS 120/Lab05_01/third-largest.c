#include <stdio.h>

int main()  {
    int numinputs = 0, largest = 0, second = 0, third = 0, swap = 0, input = 0, num = 0;

    /* Ask user for values */
    printf("Please enter the number of integers:");
    scanf("%d", &numinputs);
    
    if (numinputs< 3) {
        printf("There is no third largest number.\n");
        return 0;
    }

    scanf("%d%d%d", &largest, &second, &third);

    /* Reorganize largest, second and third */
    if (third > largest) {
        swap = largest;
        largest = third;
        third = swap;
    }
    if (third > second) {
        swap = second;
        second = third;
        third = swap;
    }    
    if (second > largest) {
        swap = largest;
        largest = second;
        second = swap;
    }


    /* Checks with other input and swaps if larger than any of the 3 */
    
    for (num = numinputs - 3; num != 0; num--)
    {
        scanf("%d", &input);

        if (input > largest) {
            third = second;
            second = largest;
            largest = input;
            continue;
        }        
        if (input > second) {
            third = second;
            second = input;
            continue;
        }   
        if (input > third) {
            third = input;
            continue;
        }
    }

    printf("The third largest number is %d\n", third);
    return 0;
}
