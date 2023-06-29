/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : Francisco Castillo Rojas
Student ID#: 148904212
Email      : fcastillo-rojas1@myseneca.ca
Section    : NJJ
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_INCOME 500
#define MAX_INCOME 400000
#define MIN_ITEM_LIST 1
#define MAX_ITEM_LIST 10
#define MIN_COST 100

int main(void)
{
    float income;
    int item_list, flag = 0;
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
//INCOME
    while (flag == 0)
    {        
        printf("\nEnter your monthly NET income: $");
        scanf("%f", &income);
        
        if (income < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (income > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        else
        {
            flag = 1;
        }
    }
 //ITEM LIST
    while (flag == 1)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &item_list);
        
        if (item_list < 1)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else if (item_list > 10)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else 
        {      
            flag = 2;
            //printf("\n******income success. check_ITEM_LIST********* flag: %d\n", flag);          
        }
    }
//DETAILS
    while (flag == 2)
    {
        flag = 3;
        int i;
        int index[ item_list ];
        int priority[item_list];
        char array_financed[3];
        char financed;
        float COST_array[item_list];

        for (i=0; i < item_list; i++)
        {
            index[i] = i+1;
            printf("\nItem-%d Details:\n",i+1);
            do{
                printf("   Item cost: $");
                scanf("%f", &COST_array[i]);
                if (COST_array[i] < MIN_COST)
                {
                    flag = 3;
                    printf("      ERROR: Cost must be at least $100.00\n");
                }
                else
                {
                    flag = 4;
                }
            }while(flag == 3);
            
            while (flag == 4)
            {
                printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                scanf("%d", &priority[i]);
                if ((priority[i] >= 1) && (priority[i] <= 3))
                {
                    flag = 5;
                }
                else
                {
                    flag = 4;
                    printf("      ERROR: Value must be between 1 and 3\n");
                }
            }

            while (flag == 5)
            {
                financed =0;
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &financed);

                  switch(financed) 
                  { 
                    case 'y':
                    flag =6;
                      //printf("You responded in the affirmative.\n");
                      array_financed[i]=financed;
                      break; 
                
                    case 'n':
                    flag=6;
                        array_financed[i]=financed;
                      //printf("You responded in the negative.\n"); 
                      break; 
                
                    default: 
                    flag =5;
                      printf("      ERROR: Must be a lowercase 'y' or 'n'\n"); 
                      break; 
                  } 
               
            }
            
        }
    // GET lenght of arrays    
        int SIZE_arrays = sizeof index / sizeof index[0];
    
    // Declare variable Total that i will use to store the SUM of array COST
        float Total;
    // Declaration variables of sum according to the choice selected.
        double sum_1, sum_2, sum_3;
    //PRINT SUMMARY of ITEMS LIST
        printf("\n");
        printf("Item Priority Financed        Cost\n");
        printf("---- -------- -------- -----------\n");
    
        for ( i = 0; i < SIZE_arrays; i++)
        {
        //Convert from  ASCII Code to letter
            char decision = (array_financed[i] == 121 ? 'y': 'n' );
        //Print each item of the differents arrays
            printf("%3d  %5d    %5c    %11.2lf\n", index[i], priority[i], decision, COST_array[i]);

        //Get total of COST
            Total = Total + COST_array[i];

            if (priority[i] == 1)
                { 
                    sum_1 += COST_array[i];
                }
            else if (priority[i] == 2)
                { 
                    sum_2 += COST_array[i];
                }
            else if (priority[i] ==3)
                { 
                    sum_3 += COST_array[i];
                }
        }
        

        printf("---- -------- -------- -----------\n"); 
        printf("                      $%11.2lf\n\n", Total+0.07);

        //printf(" sum    %.2lf", sum_1);

    //MENU whish list SELECTION
        int select;
        int choice;
        do
        {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf (" %d", &select);    
            
            printf("\n");
            
            switch (select)
            {
                case 1:
                    printf("====================================================\n");
                    printf("Filter:   All items\n"); 
                    printf("Amount:   $%.2lf\n", Total+0.07);
                    double debt = (Total +0.07) / income;
                    int years = debt / 12;
                    int m = ((int)debt) % ((int)12);
                    int months = (int)(m < 0 ? (m - 0.5) : (m + 0.5));

                    printf("Forecast: %d years, %d months\n", years, (months+1));
                    printf("NOTE: Financing options are available on some items.\n"); 
                    printf("      You can likely reduce the estimated months.\n");
                    printf("====================================================\n\n");

                    break;
                case 2:                    
                    printf("What priority do you want to filter by? [1-3]: ");
                    scanf (" %d", &choice);
                    switch (choice)
                    {
                        case 1:
                            printf("\n====================================================\n");
                            printf("Filter:   by priority (%d)\n", choice); 
                            printf("Amount:   $%.2lf\n", sum_1);
                            double debt1 = (sum_1) / income;
                            int years1 = debt1 / 12;
                            int m1 = ((int)debt1) % ((int)12);
                            int months1 = (int)(m1 < 0 ? (m1 - 0.5) : (m1 + 0.5)); 
                            printf("Forecast: %d years, %d months\n", years1, (months1+1)); 
                            printf("NOTE: Financing options are available on some items.\n"); 
                            printf("      You can likely reduce the estimated months.\n");
                            printf("====================================================\n\n");
                            break;
                        case 2:
                            printf("\n====================================================\n");
                            printf("Filter:   by priority (%d)\n", choice);  
                            printf("Amount:   $%.2lf\n", sum_2); 
                            double debt2 = (sum_2) / income;
                            int years2 = debt2 / 12;
                            int m2 = ((int)debt2) % ((int)12);
                            int months2 = (int)(m2 < 0 ? (m2 - 0.5) : (m2 + 0.5));  
                            printf("Forecast: %d years, %d months\n", years2, (months2+1)); 
                            printf("====================================================\n\n");
                            break;
                        case 3:
                            printf("\n====================================================\n");
                            printf("Filter:   by priority (%d)\n", choice);  
                            printf("Amount:   $%.2lf\n", sum_3); 
                            double debt3 = (sum_3) / income;
                            int years3 = debt3 / 12;
                            int m3 = ((int)debt3) % ((int)12);
                            int months3 = (int)(m3 < 0 ? (m3 - 0.5) : (m3 + 0.5));  
                            printf("Forecast: %d years, %d months\n", years3, (months3+1)); 
                            printf("NOTE: Financing options are available on some items.\n"); 
                            printf("      You can likely reduce the estimated months.\n");
                            printf("====================================================\n\n");
                            break;
                        
                        default:
                            printf("error in choice\n");
                            break;
                    }
                    break;
                case 0:
                    select = 0;
                    printf("Best of luck in all your future endeavours!\n");
                    break;
                
                default:
                    printf("ERROR: Invalid menu selection.\n\n");
                    break;
            } 
        } while (select != 0 );

    }

    return 0;
}
