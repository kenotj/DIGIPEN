#include <stdio.h>

int main() {
    int valueA = 0,valueB = 0, valueC = 0, valueR = 0;
    printf("Please enter A:");
    scanf("%d", &valueA);
    printf("Please enter B:");
    scanf("%d", &valueB);
    
    if (valueA < 0 || valueB < 0) {
        printf("You have entered the wrong input type.");
        return 0;
    }
    
    if (valueA < valueB) {
        valueC = valueB;
        valueB = valueA;
        valueA = valueC;
    }
    
    while (1) {
        
        if (valueB == 0) {
            printf("%d is the GCD\n", valueA);
            break;
        }   else {
            valueR = valueA - valueB;
        }
        
    
        if (valueR < valueB) {
            valueA = valueB;
        }
        else {
            valueA = valueR;
        }
        
        if (valueR < valueB) {
            valueB = valueR;
        }
    }
    
    return 0;
}
