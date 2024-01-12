/*
*****************************************************************************
                          Workshop - #6 (P1)
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
        char array[3];
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
                      array[i]=financed;
                      break; 
                
                    case 'n':
                    flag=6;
                        array[i]=financed;
                      //printf("You responded in the negative.\n"); 
                      break; 
                
                    default: 
                    flag =5;
                      printf("      ERROR: Must be a lowercase 'y' or 'n'\n"); 
                      break; 
                  } 
               
            }
            
        }

        char a = (array[0] == 121 ? 'y': 'n' );
        char b = (array[1] == 121 ? 'y': 'n' );
        char c = (array[2] == 121 ? 'y': 'n' );
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    printf("%3d  %5d    %5c    %11.2lf\n", index[0], priority[0], a, COST_array[0]);
    printf("%3d  %5d    %5c    %11.2lf\n", index[1], priority[1], b, COST_array[1]);
    printf("%3d  %5d    %5c    %11.2lf\n", index[2], priority[2], c, COST_array[2]);
    printf("---- -------- -------- -----------\n"); 
    printf("                      $%11.2lf\n\n", (COST_array[0] + COST_array[1]+COST_array[2]+0.02));

    printf("Best of luck in all your future endeavours!\n");

    //printf("\n First Element of array has values of a = [%c]\n", (array[0] == 121 ? 'y': 'n' ));
    //printf("\n Second Element of array has values of a = [%c]\n", (array[1] == 121 ? 'y': 'n' ));
    //printf("\n Third Element of array has values of a = [%c]\n", (array[2] == 121 ? 'y': 'n' )); 
    
    }

    return 0;
}
