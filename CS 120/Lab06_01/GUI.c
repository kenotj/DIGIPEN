#include <stdio.h>

int main() {
  printf("Description     Unit Price      Qty     Amount\n");

  int itemNum = 100, unitDollars= 200, unitCents = 40, qty = 700, amountDollars = 200, amountCents = 4;
  printf("Item %3d            %3d.%2d      %-3d     %3d.%2d\n\n", itemNum, unitDollars, unitCents, qty, amountDollars, amountCents);
  printf("                                Total:  %3d.%2d", unitDollars, unitCents);
  printf("                                 Paid:  %3d.%2d", unitDollars, unitCents);
  printf("                               Change:  %3d.%2d", unitDollars, unitCents);

  return 0;
} 

/* 
Description     Unit Price      Qty     Amount
                                Total:  511.2
                                 Paid:
                               Change:
 */