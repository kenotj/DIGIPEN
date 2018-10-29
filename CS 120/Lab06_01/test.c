#include<stdio.h>


int main()
{
    /****** DECLARATIONS ******/
    /* User Input Dollars and Cents */
    int inDollars = 0;
    int inCents = 0;
    int itemCounter = 0;
    
    /* User Input Item Number and Quantity */
    int inItemNumber = 0;
    int inQty = 0;
    
    
    /* Memory bank for dollars and cents */
    int itemDollars[300] = {0};
    int itemCents[300] = {0};
    
    /* Memory bank for Item Number and Quantity */
    int itemNumber[1000] = {0};
    int itemQty[1000] = {0};
    int totalQty[300] = {0};
    
    /* Memory Bank for Total Amount */
    int amountDollars[300] = {0};
    int amountCents[300] = {0};
    
    
    int lineDollars[1000] = {0};
    int lineCents[1000] = {0};
    
    /* Memory bank for Customer Amount giving */
    int inRecieveDollars = 0;
    int inRecieveCents = 0;
    
    
    /* Payable and Change */
    int payableDollars = 0;
    int payableCents = 0;
    int changeDollars = 0;
    int changeCents = 0;
    
    /* Characters used for Checking */
    char a = 0, b = 0, dotCheck = '.';
    
    /* Tmp int used for counting loops */
    int j = 0, i = 0;
    
    
    /******* CHECKING ******/
    /* LOOP CHECK if its value for Items, put into array */
    /* Check if its item number and Qty, put into array. */
    for(i=0, a = '.'; i < 300 ; ++i)    {
        scanf("%d%c%d", &inDollars, &a, &inCents);
        
        if (a == dotCheck) {
            itemDollars[i] = inDollars;
            itemCents[i] = inCents;
            ++itemCounter;
        } 
        if (a != dotCheck) {
            i = 0;
            itemNumber[i] = inDollars;
            itemQty[i] = inCents;
            break;
        }
    }
    
    
    /* LOOP CHECK if its item number and Qty, put into array. */
    for(i=1, b = '.'; i < 1000 ; ++i)    {
        scanf("%d%c%d", &inItemNumber, &b, &inQty);
        
        if (b != dotCheck) {
            itemNumber[i] = inItemNumber;
            itemQty[i] = inQty;
        }   else 
        if (b == dotCheck) {
            inRecieveDollars = inItemNumber;
            inRecieveCents = inQty;
            break;
        }
    }
    
    /****** CALCULATING ******/
    
    /* Total Amount for each line */
    for(j=0; j<300; j++){
        for(i=0; i<1000; i++) {
            if(itemNumber[i] == j) {
                lineDollars[i] = itemDollars[j] * itemQty[i];
                lineCents[i] = itemCents[j] * itemQty[i];
                
                if (lineCents[i] >= 100) {
                    lineDollars[i] += lineCents[i] /100;
                    lineCents[i] %= 100;
                }
            }
        }
    }
    
    /* Total Qty for each item */
    for(j=0; j<300; j++){
        for(i=0; i<1000; i++) {
            if(itemNumber[i] == j)
                totalQty[j] += itemQty[i];
        }
    }
    
    /* Total amount of each item in Dollars and Cents */
    for(i=0; i<300; ++i) {
        amountDollars[i] = itemDollars[i] * totalQty[i];
        amountCents[i] = itemCents[i] * totalQty[i];
        
        amountDollars[i] += amountCents[i] / 100;
        amountCents[i] = amountCents[i]% 100;
    }
    
    /* Total payable Dollars and Cents */
    for(i=0; i<300; ++i) {
        payableDollars += amountDollars[i];
        payableCents += amountCents[i];
    }
    payableDollars += payableCents / 100;
    payableCents = payableCents % 100;
    
    
    /* Calculate Change */
    /* POSITIVE */
    if (inRecieveDollars > payableDollars || inRecieveCents > payableCents) {
        if (inRecieveCents >= payableCents) {
            changeCents = inRecieveCents - payableCents;
            
            changeDollars = inRecieveDollars - payableDollars;
        }
        else
            if (inRecieveCents < payableCents) {
                changeDollars = -1;
                changeCents = 100;
                changeCents += inRecieveCents - payableCents;
                
                changeDollars += inRecieveDollars - payableDollars;
            }
    }
    /* NEGATIVE */
    if(inRecieveDollars < payableDollars || inRecieveCents < payableCents){
        if (inRecieveCents >= payableCents) {
            changeDollars = -1;
            changeCents = 100;
            changeCents += payableCents - inRecieveCents;
            
            changeDollars += payableDollars - inRecieveDollars;
            changeDollars *= -1;
        } else
            if (inRecieveCents < payableCents) {
                changeCents = payableCents - inRecieveCents;
                changeDollars = payableDollars - inRecieveDollars;
                changeDollars *= -1;
            }
        
        
    }
    
    
    
    
    
    printf("Description    Unit Price    Qty    Amount\n");
    
    for(i=0; i<itemCounter; ++i) {
        if (itemQty[i] >= 0 && itemCents[i] >= 0 && itemDollars[i] >= 0) {
            printf("Item %3d", itemNumber[i]);
            
            for(j=0; j<300; ++j) {
                if(itemNumber[i] == j)
                    printf("           %3d.%2d    %-3d    %3d.%2d\n", itemDollars[j], itemCents[j], itemQty[i], lineDollars[i], lineCents[i]);
            }
        }
    }

    for(i=0; i< 1000; ++i) {
        j = itemNumber[i];
        if(itemCents[j] == 0 && itemDollars[j] == 0)
            printf("Item %d not sold.\n", j);
    }

    printf("                             Total: %3d.%2d\n", payableDollars, payableCents);
    printf("                              Paid: %3d.%2d\n", inRecieveDollars, inRecieveCents);
    printf("                            Change:%4d.%2d\n", changeDollars, changeCents);
    
    /*
     printf("This is the first value %d.%d\n", itemDollars[0], itemCents[0]);
     printf("This is the second value %d.%d\n", itemDollars[1], itemCents[1]);
     printf("This is the third value %d.%d\n\n", itemDollars[2], itemCents[2]);
     
     printf("The total qty for Item 0 is %d\n", totalQty[0]);
     printf("The total qty for Item 1 is %d\n\n", totalQty[1]);
     
     printf("The total amount for the first item is $%d.%d\n\n", amountDollars[0],amountCents[0]);
     printf("Cash recieved by customer is %d.%d\n\n", inRecieveDollars,inRecieveCents);
     printf("The total amount to be paid is $%d.%d\n\n", payableDollars, payableCents);
     printf("The Change to be given is $%d.%d\n", changeDollars, changeCents);
     */
    
    return 0;
}
