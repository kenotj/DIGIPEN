/*
 printf("\n\ninput = %d, i = %d, numDigits = %d, divisor = %d, j = %d, k = %d", input, i, numDigits, divisor, j, k);
 */
#include <stdio.h>

int main() {
    int input = 0, i = 0, numDigits = 0, divisor = 1, j = 0, k = 0, l=0;
    printf("Please enter a number:");
    scanf("%d", &input);
    
    if (input==0) {
        printf("0=0");
    }
    
    i = input;
    
    while (i>0) {
        i = i / 10;
        numDigits = numDigits +1;
        
    }

    while (numDigits != 0) {
        divisor*=10;
        numDigits-=1;
    }
    
    divisor/=10;

    j = input;
    while (divisor!=0) {
        j = input / divisor;
        divisor/=10;
        k = j % 10;

        if (divisor==0) {
            l += k;
            printf("%d=%d\n", k, l);
        }

        else {
            l += k;
            printf("%d+", k);
        }

    }
    
    return 0;
}
